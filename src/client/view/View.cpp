#include "View.h"
#include <iostream>
#include <random>
#include <client/model/Events/model/unit/UnitMoveStepEvent.h>
#include <client/model/Events/model/bullet/BulletMoveStepEvent.h>
#include <client/model/Events/view/CameraMoveStepEvent.h>
#include <client/model/Model.h>

View::View(const Map &map, EventHandler &eventHandler, Camera &camera)
    : window(), panel(window.getRender()), eventHandler(eventHandler), camera(camera) {
  _quit = false;

  createInitialTerrainVista(map.getMap());
  createInitialTerrainObjectVista(map.getTerrainObjects());
  createInitialBuildVista(map.getBuilds());
  createInitialUnitVista(map.getUnits());
  createInitialCapturableVista(map.getCapturables());
  this->side_board = new Side_Board(&window);
}

View::~View() {
  delete this->side_board;
}

void View::createInitialTerrainVista(const std::map<Position, Tile> &map) {
  for (auto const &posMap : map) {
    Tile tile = posMap.second;
    TerrainType terrainType = tile.getTerrainType();
    Position pos = tile.getCornerPosition();
    ObjectMapaVista *terrain = VistasFactory::getTerrainVista(terrainType, pos);
//    add(terrain, tile.getCornerPosition());
//    panel.add(terrain);

    terrainsVista.emplace(pos, terrain);
  }
}

void View::createInitialTerrainObjectVista(const std::map<TerrainObjectID,
                                           TerrainObjectState> &terrainObjects) {
  for (auto const &terrainObject : terrainObjects) {
    TerrainObjectType type = terrainObject.first.getType();
    Position pos = terrainObject.second.centerPosition;
    std::string state("");
    ObjectMapaVista *terrainObjVista = VistasFactory::getTerrainObjectVista(type, state, pos);

    terrainObjectsVista.emplace(terrainObject.first, terrainObjVista);
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
//    Position pos = translateModelPos(type, action, unit.second.position);
    Sprite *unitVista = VistasFactory::getUnitVista(type, color,
                                                    action, rotation,
                                                    unit.second.position);
//    add(unitVista, pos);
//    panel.add(unitVista);

    unitsVista.emplace(unit.first, unitVista);
  }
}

void View::createInitialBuildVista(const std::map<BuildID, BuildState> &builds) {
  for (auto const &build : builds) {
    BuildType type = build.first.getType();
    Position pos = build.second.position;
    std::string state("");
    ObjectMapaVista *buildVista = VistasFactory::getBuildVista(type, state, pos);
//    add(buildVista, pos);
//    panel.add(buildVista);

    buildsVista.emplace(build.first, buildVista);
  }
}

void View::createInitialCapturableVista(const std::map<CapturableID,
                                        CapturableState> &capturables) {
  for (auto const &capturable : capturables) {
    CapturableType type = capturable.first.getType();
    if (type == FLAG) {
      std::string color = capturable.second.ownerID.getColor();
      Position pos = capturable.second.pos;
      ObjectMapaVista *capturableVista = VistasFactory::getFlagsVista(color, pos);
      capturablesVista.emplace(capturable.first, capturableVista);
    }
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

  for (auto const &posTerrainObj : terrainObjectsVista) {
    panel.add(posTerrainObj.second);
  }

  for (auto const &build : buildsVista) {
    panel.add(build.second);
  }

  for (auto const &unit : unitsVista) {
    panel.add(unit.second);
  }

  for (auto const &capturable : capturablesVista) {
    panel.add(capturable.second);
  }

  for (auto const &bullet : bulletsVista) {
    panel.add(bullet.second);
  }

  for (Sprite *effect : effectsVista) {
    panel.add(effect);
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
  if (menu != nullptr){
    //panel.add(menu);
    menu->add_to_panel(panel);
  }
  side_board->add_to_panel(panel);
  panel.draw(camera);
}

/*
void View::add(ObjectMapaVista *objectVista, Position pos) {
    if (objectVista == NULL)
      throw std::invalid_argument("View::add() objectMapaVista es NULL");

    objectVista->setPos(pos);
    panel.add(objectVista);
}
*/

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

/*
Position View::translateModelPos(UnitType type, std::string &action, Position pos) {
  if (type == R_GRUNT || type == R_TOUGH || type == R_PYRO) {
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
*/

void View::moveCamera(int x, int y) {
  long cantSteps = eventHandler.amountSteps();
  // no hay unidades moviendose
  if (cantSteps == 0) {
    cantSteps = camera.vel;
  }

  for (int i=0; i < cantSteps; ++i) {
    eventHandler.addStep(new CameraMoveStepEvent(camera, x, y), i);
  }
}


void View::move(UnitID id, Position posTo) {
  Position pos_aux = unitsVista.at(id)->getPos();
  std::string action("walk");
//  posTo = translateModelPos(id.getType(), action, posTo);

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


ObjectMapaVista* View::getTerrainObjectVista(TerrainObjectID id) {
  return terrainObjectsVista.at(id);
}

void View::removeTerrainObjectVista(const TerrainObjectID &id) {
  delete terrainObjectsVista.at(id);
  terrainObjectsVista.erase(id);

}

void View::addTerrainObjectVista(TerrainObjectID &id,
                                 ObjectMapaVista *terrainObjectVista) {
  terrainObjectsVista.emplace(id, terrainObjectVista);
}

Sprite* View::getUnitVista(UnitID id) {
  return unitsVista.at(id);
}

void View::removeUnitVista(const UnitID &id) {
  delete unitsVista.at(id);
  unitsVista.erase(id);
}

void View::addUnitVista(const UnitID &id, Sprite *unitVista) {
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

ObjectMapaVista* View::getCapturedVista(const CapturableID &id) {
  return capturablesVista.at(id);
}

void View::addCapturableVista(const CapturableID &id, ObjectMapaVista *capturableVista) {
  capturablesVista.emplace(id, capturableVista);
}

void View::removeCapturableVista(CapturableID &id) {
  delete capturablesVista.at(id);
  capturablesVista.erase(id);
}


void View::addExplosionVista(Sprite *objectVista) {
  if (objectVista == NULL)
    throw std::invalid_argument("View::addExplosionVista() objectMapaVista es NULL");

  explosionsVista.push_back(objectVista);
}

void View::addEffectVista(Sprite *objectVista) {
  if (objectVista == NULL)
    throw std::invalid_argument("View::addExplosionVista() objectMapaVista es NULL");

  effectsVista.push_back(objectVista);
}

void View::load_production_menu(const BuildID &factoryID,
                                const BuildState& buildState,
                                Model &model, int x, int y) {
  menu = new Production_Menu(factoryID, buildState, window, model, x, y);
}
