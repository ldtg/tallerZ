#include "View.h"
#include <string>
#include "Image.h"
#include "Sprite.h"
#include <iostream>
#include <vector>
#include <model/Events/model/unit/UnitMoveStepEvent.h>
#include <model/Events/model/bullet/BulletMoveStepEvent.h>
#include <random>
#include <model/Events/view/CameraMoveStepEvent.h>

View::View(const Map &map, EventHandler &eventHandler, Camera &camera)
    : window(), panel(window.getRender()), eventHandler(eventHandler), camera(camera) {
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
    ObjectMapaVista *terrain = VistasFactory::getTerrainVista(terrainType);
    add(terrain, tile.getCornerPosition());

    terrainsVista.emplace(pos, terrain);
  }
}

int getRandomNumInRange2(const int range_from, const int range_to) {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<int> distr(range_from, range_to);
  return distr(generator);
}

void View::createInitialUnitVista(const std::map<UnitID, UnitState> &units) {
  std::vector<int> rotations{0, 45, 90, 135, 180, 225, 270, 315};

  for (auto const &unit : units) {
    UnitType type = unit.first.getType();
    //Se elije una rotacion inicial al azar.
    int i = getRandomNumInRange2(0, 7);
    std::string rotation = std::to_string(rotations[i]);
    std::string action("look_around");
    std::string color = unit.second.owner.getColor();
    Position pos = translateModelPos(type, action, unit.second.position);
    Sprite *unitVista = VistasFactory::getUnitVista(type, color, action, rotation);

    add(unitVista, pos);

    unitsVista.emplace(unit.first, unitVista);
  }
}

void View::createInitialBuildVista(const std::map<BuildID, BuildState> &builds) {
  for (auto const &build : builds) {
    BuildType type = build.first.getType();
    Position pos = build.second.position;
    std::string state("");
    ObjectMapaVista *buildVista = VistasFactory::getBuildVista(type, state);
    add(buildVista, pos);

    buildsVista.emplace(build.first, buildVista);
  }
}


void View::update() {
  while (!eventHandler.empty()) {
    Event *event = eventHandler.get();
    event->process();
    delete (event);
  }

  drawSteps();
  draw();
}

void View::drawSteps() {
  for (int i=0; i < eventHandler.amountSteps(); i++) {
    for (Event *stepEvent : eventHandler.getSteps(i)) {
      stepEvent->process();
      delete (stepEvent);
    }
    draw();
  }
  eventHandler.clearSteps();
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

//  updateExplosion();
//  for (Sprite *explosion : explosionsVista) {
//    panel.add(explosion);
//  }
  std::vector<Sprite*>::iterator iter;
  for (iter = explosionsVista.begin(); iter != explosionsVista.end();) {
    Sprite *explosionVista = *iter;
    if (explosionVista->doCycle()) {
      iter = explosionsVista.erase(iter);
      delete explosionVista;
    }
    else {
      panel.add(explosionVista);
      ++iter;
    }
  }

  panel.draw(camera);
}

void View::add(ObjectMapaVista *objectVista, Position pos) {
    if (objectVista == NULL)
      throw std::invalid_argument("View::add() objectMapaVista es NULL");

    objectVista->setPos(pos);
    panel.add(objectVista);
}

/*
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
*/

void View::setQuit() {
  _quit = true;
}

bool View::quit() {
  return _quit;
}

Position View::translateModelPos(UnitType type, std::string &action, Position pos) {
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

void View::moveCamera(int x, int y) {
  for (int i=0; i < camera.vel; ++i) {
    eventHandler.addStep(new CameraMoveStepEvent(camera, x, y), i);
  }

//  camera.move(x, y);
}


void View::move(UnitID id, Position posTo) {
  Position pos_aux = unitsVista.at(id)->getPos();
  std::string action("walk");
  posTo = translateModelPos(id.getType(), action, posTo);

  int rotation = 0;
  int i = 0;
  while (pos_aux != posTo) {
    rotation = pos_aux.getRoration(posTo);
    pos_aux.move(posTo);
//    eventHandler.add(new UnitMoveStepEvent(id, pos_aux, rotation));
    eventHandler.addStep(new UnitMoveStepEvent(id, pos_aux, rotation), i);
    i += 1;
  }
}


Sprite* View::getUnitVista(UnitID id) {
  return unitsVista.at(id);
}

void View::removeUnitVista(UnitID &id) {
  delete unitsVista.at(id);
  unitsVista.erase(id);
}

void View::addUnitVista(UnitID &id, Sprite *unitVista) {
  unitsVista.emplace(id, unitVista);
}


ObjectMapaVista* View::getBulletVista(BulletID id) {
  return bulletsVista.at(id);
}

void View::move(BulletID id, Position posTo) {
  Position pos_aux = bulletsVista.at(id)->getPos();
  int i = 0;
  while (pos_aux != posTo) {
    pos_aux.move(posTo);
    eventHandler.addStep(new BulletMoveStepEvent(id, pos_aux), i);
    i += 1;
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
}
