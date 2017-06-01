#include "View.h"
#include <string>
#include "Image.h"
#include "Sprite.h"
#include <iostream>
#include <vector>
#include <model/Events/model/unit/UnitMoveStepEvent.h>
#include <model/Events/model/bullet/BulletMoveStepEvent.h>

View::View(const Map &map, EventHandler &eventHandler, Window& window)
    : window(window), panel(window.getRender()), eventHandler(eventHandler) {
  _quit = false;
  createInitialTerrainVista(map.getMap());
  createInitialBuildVista(map.getBuilds());
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
    std::string rotation("0");
    std::string action("look_around");
    Position pos = translatePos(type, action, unit.second.position);
    ObjectMapaVista *unitVista = getUnitVista(type, action, rotation);

    add(unitVista, pos);

    unitsVista.emplace(unit.first, unitVista);
  }
}

void View::createInitialBuildVista(const std::map<BuildID, BuildState> &builds) {
  for (auto const &build : builds) {
    BuildType type = build.first.getType();
    Position pos = build.second.position;
    std::string state("");
    ObjectMapaVista *buildVista = getBuildVista(type, state);
    add(buildVista, pos);

    buildsVista.emplace(build.first, buildVista);
  }
}

void View::updateExplosion() {
  std::vector<Sprite*>::iterator iter;
  for (iter = explosionsVista.begin(); iter != explosionsVista.end();) {
    Sprite *explosionVista = *iter;
    if (explosionVista->doCycle()) {
      iter = explosionsVista.erase(iter);
      delete explosionVista;
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
    delete (event);
    draw();
  }
  draw();
}

void View::draw() {
  for (auto const &posTerrain : terrainsVista) {
    panel.add(posTerrain.second);
  }

  for (auto const &build : buildsVista) {
    panel.add(build.second);
  }

  for (auto const &unit : unitsVista) {
    panel.add(unit.second);
  }

  for (auto const &bullet : bulletsVista) {
    panel.add(bullet.second);
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
  return vistasFactory.getTerrainVista(type);
}

ObjectMapaVista* View::getBuildVista(BuildType type, std::string &state) {
  vistasFactory.getBuildVista(type, state);
}

Sprite* View::getUnitVista(UnitType type,
                                    std::string &action,
                                    std::string &rotation) {

  return vistasFactory.getUnitVista(type, action, rotation);
}

ObjectMapaVista* View::getBulletVista(WeaponType type) {
  return vistasFactory.getBulletVista(type);
}

void View::setQuit() {
  _quit = true;
}

bool View::quit() {
  return _quit;
}

Position View::translatePos(UnitType type, std::string &action, Position pos) {
  if (type == R_GRUNT) {
    // size of grunt image is 16x16
    return pos.sub(8,8);
  }
  else if (type == V_JEEP) {
    if (action == "die")
      return pos.sub(0,10);
    else
      // size of jeep image is 40x40
      return pos.sub(25,25);
  }
}

ObjectMapaVista* View::getUnitVista(UnitID id) {
  return unitsVista.at(id);
}

void View::move(UnitID id, Position posTo) {
  Position pos_aux = unitsVista.at(id)->getPos();
  std::string action("walk");
  posTo = translatePos(id.getType(), action, posTo);

  int rotation = 0;
  while (pos_aux != posTo) {
    rotation = pos_aux.move(posTo);
    eventHandler.add(new UnitMoveStepEvent(id, pos_aux, rotation));
  }
}

void View::removeUnitVista(UnitID &id) {
  delete unitsVista.at(id);
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
  delete bulletsVista.at(id);
  bulletsVista.erase(id);
}

void View::addBulletVista(BulletID &id, ObjectMapaVista *bulletVista) {
  bulletsVista.emplace(id, bulletVista);
}


ObjectMapaVista* View::getBuildVista(BuildID id) {
  return buildsVista.at(id);
}

void View::removeBuildVista(BuildID &id) {
  delete buildsVista.at(id);
  buildsVista.erase(id);
}

void View::addBuildVista(BuildID &id, ObjectMapaVista *buildVista) {
  buildsVista.emplace(id, buildVista);
}


void View::addExplosionVista(Sprite *objectVista, Position pos) {
  if (objectVista == NULL)
    throw std::invalid_argument("View::addExplosionVista() objectMapaVista es NULL");

  objectVista->setPos(pos);
  explosionsVista.push_back(objectVista);
//  panel.add(objectVista);
}
