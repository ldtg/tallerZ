#include "View.h"
#include "ViewPosition.h"
#include "VehicleView.h"
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
      panel(window.getRender()),
      eventHandler(eventHandler),
      camera(camera) {
  _quit = false;
//  soundPlayer.start();

  createInitialTerrainVista(map.getMap());
  createInitialTerrainObjectVista(map.getTerrainObjects());
  createInitialBuildVista(map.getBuilds());
  createInitialUnitVista(map.getUnits());
  createInitialCapturableVista(map.getCapturables());

  this->side_board = new Side_Board(&window, *this, player_color);
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

//  soundPlayer.stop();
//  soundPlayer.join();
}

void View::createInitialTerrainVista(const std::map<Position, Tile> &map) {
  for (auto const &posMap : map) {
    Tile tile = posMap.second;
    TerrainType terrainType = tile.getTerrainType();
    Position pos = tile.getCornerPosition();
    ObjectMapaVista *terrain = VistasFactory::getTerrainVista(terrainType, pos);

    terrainsVista.emplace(pos, terrain);
  }
}

void View::createInitialTerrainObjectVista(const std::map<TerrainObjectID,
                                                          TerrainObjectState> &terrainObjects) {
  for (auto const &terrainObject : terrainObjects) {
    TerrainObjectType type = terrainObject.first.getType();
    Position pos = terrainObject.second.centerPosition;
    std::string state("");
    ObjectMapaVista *terrainObjVista =
        VistasFactory::getTerrainObjectVista(type, state, pos);

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

    UnitView *unitVista = nullptr;
    if (type == R_GRUNT || type == R_TOUGH || type == R_PYRO
        || type == R_LASER || type == R_PSYCHO) {
      unitVista = new UnitView(type, color, unit.second.position,
                                         action, rotation);
    }
    else if (type == V_JEEP || type == V_LTANK) {
      unitVista = new VehicleView(type, color, unit.second.position,
                               action, rotation);
    }

    unitVista->getView()->setRotation(rotations[i]);
    unitsVista.emplace(unit.first, unitVista);
  }
}

void View::createInitialBuildVista(const std::map<BuildID,
                                                  BuildState> &builds) {
  for (auto const &build : builds) {
    BuildType type = build.first.getType();
    Position pos = build.second.position;
    std::string state("");
    Image *buildVista = VistasFactory::getBuildVista(type, state, pos);
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
      ObjectMapaVista
          *capturableVista = VistasFactory::getFlagsVista(color, pos);
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

void View::draw() {
  SDL_Renderer *window_render = window.getRender();

  SDL_SetRenderDrawColor(window_render, 0xFF, 0xFF, 0xFF, 0xFF );
  SDL_RenderClear(window_render);

  for (auto const &posTerrain : terrainsVista) {
    posTerrain.second->set_texture(window_render);

    posTerrain.second->draw(window_render, camera);
//    panel.add(posTerrain.second);
  }

  for (auto const &posTerrainObj : terrainObjectsVista) {
    posTerrainObj.second->set_texture(window_render);

    posTerrainObj.second->draw(window_render, camera);
//    panel.add(posTerrainObj.second);
  }

  for (auto const &build : buildsVista) {
    build.second->set_texture(window_render);

    build.second->draw(window_render, camera);
//    panel.add(build.second);
  }

  for (auto const &capturable : capturablesVista) {
    capturable.second->set_texture(window_render);

    capturable.second->draw(window_render, camera);
//    panel.add(capturable.second);
  }

  for (auto const &bullet : bulletsVista) {
    bullet.second->getView()->set_texture(window_render);

    bullet.second->draw(window_render, camera);
//    panel.add(bullet.second->getView());
  }

  for (auto &unit : unitsVista) {
    unit.second->getView()->set_texture(window_render);

    unit.second->draw(window_render, camera);
//    panel.add(unit.second->getView());
  }

  for (Sprite *effect : effectsVista) {
    effect->set_texture(window_render);

    effect->draw(window_render, camera);
//    panel.add(effect);
  }

  for (Sprite *explosion : explosionsVista) {
    explosion->set_texture(window_render);

    explosion->draw(window_render, camera);
//    panel.add(explosion);
  }

  if (menu != nullptr) {
    //panel.add(menu);
    menu->add_to_panel(panel);
  }
  if (side_board != nullptr) {
    side_board->add_to_panel(panel);
  }
  panel.draw(camera);
//  SDL_RenderPresent(window_render);
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

ObjectMapaVista *View::getTerrainObjectVista(TerrainObjectID id) {
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

UnitView* View::getUnitView(UnitID id) {
  return unitsVista.at(id);
}

void View::removeUnitVista(const UnitID &id) {
  delete unitsVista.at(id);
  unitsVista.erase(id);
}

void View::addUnitVista(const UnitID &id, UnitView *unitVista) {
  unitsVista.emplace(id, unitVista);
}

BulletView* View::getBulletVista(BulletID id) {
  return bulletsVista.at(id);
}

void View::removeBulletVista(BulletID &id) {
  delete bulletsVista.at(id);
  bulletsVista.erase(id);
}

void View::addBulletVista(BulletID &id, BulletView *bulletVista) {
  bulletsVista.emplace(id, bulletVista);
}

ObjectMapaVista *View::getBuildVista(BuildID id) {
  return buildsVista.at(id);
}

void View::removeBuildVista(BuildID &id) {
  delete buildsVista.at(id);
  buildsVista.erase(id);
}

void View::addBuildVista(BuildID &id, ObjectMapaVista *buildVista) {
  buildsVista.emplace(id, buildVista);
}

ObjectMapaVista *View::getCapturedVista(const CapturableID &id) {
  return capturablesVista.at(id);
}

void View::addCapturableVista(const CapturableID &id,
                              ObjectMapaVista *capturableVista) {
  capturablesVista.emplace(id, capturableVista);
}

void View::removeCapturableVista(CapturableID &id) {
  delete capturablesVista.at(id);
  capturablesVista.erase(id);
}

void View::addExplosionVista(Sprite *objectVista) {
  if (objectVista == nullptr)
    return;

  explosionsVista.push_back(objectVista);
}

void View::addEffectVista(Sprite *objectVista) {
  if (objectVista == nullptr)
    throw std::invalid_argument(
        "View::addExplosionVista() objectMapaVista es NULL");

  effectsVista.push_back(objectVista);
}

SoundPlayer& View::getSoundPlayer() {
  return soundPlayer;
}

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
void View::show_unit_side_details(UnitType unitType, UnitType secondType) {
  this->side_board->load_unit_images(unitType, secondType);
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
