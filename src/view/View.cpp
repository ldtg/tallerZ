#include "View.h"
#include <string>
#include "Image.h"
#include "Sprite.h"
#include <iostream>
#include <vector>
#include <model/Events/model/UnitMoveStepEvent.h>
#include <model/Events/model/BulletMoveStepEvent.h>

View::View(const Map &map, EventHandler &eventHandler, Window& window)
    : window(window), panel(window.getRender()), eventHandler(eventHandler) {
  _quit = false;
  createInitialTerrainVista(map.getMap());
  createInitialUnitVista(map.getUnits());
}

View::~View() {}

void View::createInitialTerrainVista(const std::map<Position, Tile> &map) {
  for (auto const &posMap : map) {
    Position pos = posMap.first;
    Tile tile = posMap.second;
    TerrainType terrainType = tile.getTerrainType();
    ObjectMapaVista *terrain = getTerrainVista(terrainType);
    add(terrain, tile.getCornerPosition());

    terrainsVista.emplace(pos, terrain);
  }
}

void View::createInitialUnitVista(const std::map<UnitID, UnitState> &units) {
  for (auto const &unit : units) {
    UnitType type = unit.first.getType();
    Position pos = unit.second.position;
    std::string rotation("0");
    std::string action("look_around");
    ObjectMapaVista *unitVista = getUnitVista(type, action, rotation, 3);
    add(unitVista, pos);

    unitsVista.emplace(unit.first, unitVista);
  }
}

//void View::setEventHandler(EventHandler &eventHandler) {
//  this->eventHandler = eventHandler;
//}

void View::updateExplosion() {
  std::vector<ObjectMapaVista *>::iterator iter;
  for (iter = explosionsVista.begin(); iter != explosionsVista.end();) {
    ObjectMapaVista *explosionVista = *iter;
    if (explosionVista->doCycle()) {
      iter = explosionsVista.erase(iter);
//      delete explosionVista;
    }
    else {
      ++iter;
    }
  }
}

void View::update() {
  updateExplosion();
  while (!eventHandler.empty()) {
    Event *event = eventHandler.get();
    event->process();
    //TODO: VER QUIEN HACE DELETE EN ESTOS EVENT
//    delete (event);
    draw();
  }
  draw();
}

void View::draw() {
  for (auto const &posTerrain : terrainsVista) {
    panel.add(posTerrain.second);
  }

  for (auto const &posUnit : unitsVista) {
    panel.add(posUnit.second);
  }

  for (auto const &posBullet : unitsVista) {
    panel.add(posBullet.second);
  }

  for (ObjectMapaVista *explosion : explosionsVista) {
    panel.add(explosion);
  }

  panel.draw();
}

void View::add(ObjectMapaVista *objectVista, Position pos) {
    if (objectVista == NULL)
      throw std::invalid_argument("View::add() objectMapaVista es NULL");

    objectVista->setPos(pos);
    panel.add(objectVista);
}

ObjectMapaVista* View::getTerrainVista(TerrainType type) {
    if (type == LAND) {
        return new Image("../src/view/images/terrain/land.png");
    }
    else {
        return nullptr;
    }
}

ObjectMapaVista* View::getUnitVista(UnitType type,
                                    std::string &action,
                                    std::string &rotation,
                                    int num_frames) {
  if (type == R_GRUNT) {
    std::string path = "../src/view/images/units/grunt/" + action
                      + "/" + action + "_blue_r" + rotation + "_n";
    return new Sprite(path.c_str(), num_frames);
  }
  else {
    return nullptr;
  }
}

ObjectMapaVista* View::getBulletVista(WeaponType type) {
  if (type == ROCKET) {
    return new Image("../src/view/images/bullet/bullet.png");
  }
  else {
    return nullptr;
  }
}

void View::setQuit() {
  _quit = true;
}

bool View::quit() {
  return _quit;
}

ObjectMapaVista* View::getUnitVista(UnitID id) {
  return unitsVista.at(id);
}

void View::move(UnitID id, Position posTo) {
  Position pos_aux = unitsVista.at(id)->getPos();
  int rotation = 0;
  while (pos_aux != posTo) {
    rotation = pos_aux.move(posTo);
    eventHandler.add(new UnitMoveStepEvent(id, pos_aux, rotation));
//    unitsVista.at(id)->setPos(posTo);
//    panel.draw();
//    update();
  }
}

void View::removeUnitVista(UnitID &id) {
//  delete unitsVista.at(id);
  unitsVista.erase(id);
}

void View::addUnitVista(UnitID &id, ObjectMapaVista *unitVista) {
  unitsVista.emplace(id, unitVista);
}


ObjectMapaVista* View::getBulletVista(BulletID id) {
  return bulletsVista.at(id);
}

void View::move(BulletID id, Position posTo) {
  Position pos_aux = bulletsVista.at(id)->getPos();
  while (pos_aux != posTo) {
    pos_aux.move(posTo);
    eventHandler.add(new BulletMoveStepEvent(id, pos_aux));
  }
}

void View::removeBulletVista(BulletID &id) {
//  delete bulletsVista.at(id);
  bulletsVista.erase(id);
}

void View::addBulletVista(BulletID &id, ObjectMapaVista *bulletVista) {
  bulletsVista.emplace(id, bulletVista);
}

void View::addExplosionVista(ObjectMapaVista *objectVista, Position pos) {
  if (objectVista == NULL)
    throw std::invalid_argument("View::addExplosionVista() objectMapaVista es NULL");

  objectVista->setPos(pos);
  explosionsVista.push_back(objectVista);
  panel.add(objectVista);
}
