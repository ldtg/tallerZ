#include "View.h"
#include "ViewPosition.h"
#include "client/view/unit/VehicleView.h"
#include <random>
#include <client/model/Model.h>
#include <thread>
#include <client/front_end/SDL_Interface/Menus/Result/Victory.h>
#include <client/front_end/SDL_Interface/Menus/Result/Defeat.h>

View::View(const Map &map,
           EventHandler &eventHandler,
           Camera &camera,
           const std::string &player_color)
    : window(),
      eventHandler(eventHandler),
      camera(camera),
      playerColor(player_color) {
  _quit = false;

  createInitialTerrainView(map.getMap());
  createInitialTerrainObjectView(map.getTerrainObjects());
  createInitialBuildingView(map.getBuilds());
  createInitialUnitView(map.getUnits());
  createInitialCapturableView(map.getCapturables());

}

View::~View() {
  for (auto &par : terrainsVista) {
    delete par.second;
  }
  for (auto &par : terrainObjectsVista) {
    delete par.second;
  }
  for (auto &par : buildsVista) {
    delete par.second;
  }
  for (auto &par : capturablesVista) {
    delete par.second;
  }
  for (auto &par : bulletsVista) {
    delete par.second;
  }
  for (auto &exp : explosionsVista) {
    delete exp;
  }
  for (auto &exp : effectsVista) {
    delete exp;
  }
  for (auto &par : unitsVista) {
    delete par.second;
  }
  delete this->side_board;
  if (menu != nullptr) { delete this->menu; }
}

void View::createInitialTerrainView(const std::map<Position, Tile> &map) {
  for (auto const &posMap : map) {
    Tile tile = posMap.second;
    TerrainType terrainType = tile.getTerrainType();
    Position pos = tile.getCornerPosition();
    Image *terrain = ViewFactory::getTerrainVista(terrainType, pos);

    terrainsVista.emplace(pos, terrain);
  }
}

void View::createInitialTerrainObjectView(const std::map<TerrainObjectID,
                                                         TerrainObjectState> &terrainObjects) {
  for (auto const &terrainObject : terrainObjects) {
    TerrainObjectType type = terrainObject.first.getType();
    Position pos = terrainObject.second.centerPosition;
    std::string state("");
    Image *terrainObjVista = ViewFactory::getTerrainObjectVista(type, state, pos);
    terrainObjectsVista.emplace(terrainObject.first, terrainObjVista);
  }
}


int getRandomNumInRange2(const int min, const int max) {
  return min + (rand() % (max - min + 1));
}

void View::createInitialUnitView(const std::map<UnitID, UnitState> &units) {
  std::vector<int> rotations{0, 45, 90, 135, 180, 225, 270, 315};
  for (auto const &unit : units) {
    UnitType type = unit.first.getType();
    //Se elije una rotacion inicial al azar.
    int i = getRandomNumInRange2(0, 7);
    std::string rotation = std::to_string(rotations[i]);
    std::string action("look_around");
    std::string color = unit.second.owner.getColor();

    UnitView *unitVista = ViewFactory::getUnitView(type, color,
                                                     action, rotation,
                                                     unit.second.position);
    unitVista->getView()->setDrawRotation(rotations[i]);
    unitsVista.emplace(unit.first, unitVista);
  }
}

void View::createInitialBuildingView(const std::map<BuildID,
                                                    BuildState> &builds) {
  for (auto const &build : builds) {
    BuildType type = build.first.getType();
    Position pos = build.second.position;
    std::string color = build.second.owner.getColor();
    std::string level = std::to_string(build.second.techLevel);
    BuildingView *buildVista = ViewFactory::getBuildingVista(type, level, color, pos);
    if (!build.second.owner.isGaia()) buildVista->capture(color);
    buildsVista.emplace(build.first, buildVista);
  }
}

void View::createInitialCapturableView(const std::map<CapturableID,
                                                      CapturableState> &capturables) {
  for (auto const &capturable : capturables) {
    CapturableType type = capturable.first.getType();
    // Los vehiculos capturables se dibujan en createInitialUnitView
    if (type == FLAG) {
      std::string color = capturable.second.ownerID.getColor();
      Position pos = capturable.second.pos;
      Sprite *capturableVista = ViewFactory::getFlagsVista(color, pos);
      capturablesVista.emplace(capturable.first, capturableVista);
    }
  }
}

void View::tick() {
  float fps = 40;
  unsigned long milifps =
      (unsigned long) std::lround((1 / fps) * 1000);

  auto begin = std::chrono::high_resolution_clock::now();

  while (!eventHandler.empty()) {
    Event *event = eventHandler.get();
    event->process();
    delete (event);
  }
  update();
  draw();

  auto end = std::chrono::high_resolution_clock::now();
  auto diff =
      std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
  auto sleepTime = std::chrono::milliseconds(milifps) - diff;
  std::this_thread::sleep_for(sleepTime);
}

void View::update() {
  for (auto &unit : unitsVista) {
    unit.second->update();
  }
  for (auto const &bullet : bulletsVista) {
    bullet.second->update();
  }
  updateExplosions();
}

void View::updateExplosions() {
  std::vector<ExplosionView*>::iterator iter;
  for (iter = explosionsVista.begin(); iter != explosionsVista.end();) {
    ExplosionView *explosionVista = *iter;
    if (explosionVista->doCycle()) {
      iter = explosionsVista.erase(iter);
      delete explosionVista;
    }
    else {
      ++iter;
    }
  }
}

void View::draw() {
  SDL_Renderer *window_render = window.getRender();

  SDL_SetRenderDrawColor(window_render, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(window_render);

  for (auto const &posTerrain : terrainsVista) {
    posTerrain.second->draw(window_render, camera);
  }

  for (auto const &posTerrainObj : terrainObjectsVista) {
    posTerrainObj.second->draw(window_render, camera);
  }

  for (auto const &build : buildsVista) {
    build.second->draw(window_render, camera);
  }

  for (auto const &capturable : capturablesVista) {
    capturable.second->draw(window_render, camera);
  }

  for (auto const &bullet : bulletsVista) {
    bullet.second->draw(window_render, camera);
  }

  for (auto &unit : unitsVista) {
    unit.second->draw(window_render, camera);
  }

  for (Sprite *effect : effectsVista) {
    effect->draw(window_render, camera);
  }

  for (ExplosionView *explosion : explosionsVista) {
    explosion->draw(window_render, camera);
  }

  if (side_board != nullptr) {
    side_board->draw(window_render, camera);
  }
  if (menu != nullptr) {
    menu->draw(window_render, camera);
  }

  SDL_RenderPresent(window_render);
}

void View::setQuit() {
  _quit = true;
}

bool View::quit() {
  return _quit;
}

Camera& View::getCamera() const {
  return camera;
}

Image *View::getTerrainObjectView(const TerrainObjectID &id) const {
  return terrainObjectsVista.at(id);
}

void View::removeTerrainObjectView(const TerrainObjectID &id) {
  delete terrainObjectsVista.at(id);
  terrainObjectsVista.erase(id);

}

void View::addTerrainObjectView(const TerrainObjectID &id,
                                Image *terrainObjectView) {
  terrainObjectsVista.emplace(id, terrainObjectView);
}

UnitView* View::getUnitView(const UnitID &id) const {
  return unitsVista.at(id);
}

void View::removeUnitView(const UnitID &id) {
  delete unitsVista.at(id);
  unitsVista.erase(id);
}

void View::addUnitView(const UnitID &id, UnitView *unitView) {
  unitsVista.emplace(id, unitView);
}

BulletView* View::getBulletView(const BulletID &id) const {
  return bulletsVista.at(id);
}

void View::removeBulletView(const BulletID &id) {
  delete bulletsVista.at(id);
  bulletsVista.erase(id);
}

void View::addBulletView(const BulletID &id, BulletView *bulletView) {
  bulletsVista.emplace(id, bulletView);
}

BuildingView* View::getBuildingView(const BuildID &id) {
  return buildsVista.at(id);
}

//void View::removeBuildView(const BuildID &id) {
//  delete buildsVista.at(id);
//  buildsVista.erase(id);
//}

//void View::addBuildView(const BuildID &id, Image *buildView) {
//  buildsVista.emplace(id, buildView);
//}

Sprite *View::getCapturedView(const CapturableID &id) {
  return capturablesVista.at(id);
}

void View::addCapturableView(const CapturableID &id,
                             Sprite *capturableView) {
  capturablesVista.emplace(id, capturableView);
}

void View::removeCapturableView(const CapturableID &id) {
  delete capturablesVista.at(id);
  capturablesVista.erase(id);
}

void View::addExplosionView(ExplosionView *objectVista) {
  // Las balas no tienen vista de explosion.
  if (objectVista == nullptr)
    return;

  explosionsVista.push_back(objectVista);
}

void View::addEffectView(Sprite *effectView) {
  if (effectView == nullptr)
    throw std::invalid_argument("View::addExplosionView()"
                                " effectView es NULL");

  effectsVista.push_back(effectView);
}

//SoundPlayer& View::getSoundPlayer() {
//  return soundPlayer;
//}

void View::load_production_menu(const BuildID &factoryID,
                                const BuildState &buildState,
                                Model &model, int x, int y) {
  menu = new Production_Menu(factoryID, buildState, window, model, x, y);
}

void View::load_quit_menu() {
  this->menu = new Quit_Menu(window, *this);
}

Menu *View::get_present_menu() {
  return this->menu;
}

void View::show_unit_side_details(UnitID unitID) {
  this->side_board->load_unit_images(unitID);
}

void View::clear_unit_side_details() {
  this->side_board->clean_unit_images();
}

void View::free_menu() {
  delete menu;
  menu = nullptr;
}

Side_Board *View::get_side_board() {
  return this->side_board;
}

void View::show_victory() {
  if (this->menu != nullptr){
    free_menu();
  }
  this->menu = new Victory(window, *this);
}

void View::show_defeat() {
  if (this->menu != nullptr){
    free_menu();
  }
  this->menu = new Defeat(window, *this);
}
