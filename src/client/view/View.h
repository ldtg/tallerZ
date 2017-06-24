#ifndef TALLERZ_VISTA_H
#define TALLERZ_VISTA_H

class EventHandler;
class Model;
//class Quit_Menu;
#include "common/Map/Map.h"
#include "Window.h"
#include <string>
#include <client/front_end/SDL_Interface/Menus/Production/Production_Menu.h>
#include <client/front_end/SDL_Interface/Side_Board.h>
#include "client/model/Events/EventHandler.h"
#include <client/view/ObjectMapaVista.h>
#include "Sprite.h"
#include "VistasFactory.h"
#include "Camera.h"
#include "UnitView.h"
#include "BulletView.h"
#include "client/view/sounds/SoundPlayer.h"
#include <client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.h>

class View {
 private:
  Window window;
  Camera &camera;
  Menu * menu = nullptr;
  Side_Board * side_board = nullptr;
  EventHandler &eventHandler;
//  SoundPlayer soundPlayer;

  bool _quit;

  std::map<Position, ObjectMapaVista*> terrainsVista;
  std::map<TerrainObjectID, ObjectMapaVista*> terrainObjectsVista;
  std::map<BuildID, ObjectMapaVista*> buildsVista;
  std::map<UnitID, UnitView*> unitsVista;
  std::map<CapturableID, ObjectMapaVista*> capturablesVista;
  std::map<BulletID, BulletView*> bulletsVista;
  std::vector<Sprite*> effectsVista;
  std::vector<ExplosionView*> explosionsVista;

  void createInitialTerrainVista(const std::map<Position, Tile> &map);
  void createInitialTerrainObjectVista(const std::map<TerrainObjectID,
                                       TerrainObjectState> &terrainObjects);
  void createInitialUnitVista(const std::map<UnitID, UnitState> &units);
  void createInitialBuildVista(const std::map<BuildID, BuildState> &builds);
  void createInitialCapturableVista(const std::map<CapturableID,
                                                   CapturableState> &capturables);

  void updateExplosions();
  void update();
  void draw();

 public:
  View(const Map &map, EventHandler &eventHandler,
       Camera &camera, const std::string& player_color);
  ~View();

  void setQuit();
  bool quit();

  Camera &getCamera() const;

  ObjectMapaVista* getTerrainObjectVista(TerrainObjectID id);
  void removeTerrainObjectVista(const TerrainObjectID &id);
  void addTerrainObjectVista(TerrainObjectID &id,
                             ObjectMapaVista *terrainObjectVista);

  UnitView *getUnitView(UnitID id);
//  void move(UnitID id, Position posTo);
  void removeUnitVista(const UnitID &id);
  void addUnitVista(const UnitID &id, UnitView *unitVista);

  BulletView *getBulletVista(BulletID id);
//  void move(BulletID id, Position posTo);
  void removeBulletVista(BulletID &id);
  void addBulletVista(BulletID &id, BulletView *bulletVista);

  ObjectMapaVista *getBuildVista(BuildID id);
  void removeBuildVista(BuildID &id);
  void addBuildVista(BuildID &id, ObjectMapaVista *buildVista);

  ObjectMapaVista *getCapturedVista(const CapturableID &id);
  void addCapturableVista(const CapturableID &id,
                          ObjectMapaVista *capturableVista);
  void removeCapturableVista(CapturableID &id);

  void addExplosionVista(ExplosionView *explosionView);
  void addEffectVista(Sprite *objectVista);

//  SoundPlayer& getSoundPlayer();

  /*************************************************/
  Menu *get_present_menu();
  void load_production_menu(const BuildID& factoryID,
                            const BuildState& buildState,
                            Model& model, int x, int y);
  void load_quit_menu();
  Side_Board * get_side_board();
  void free_menu();
  void show_unit_side_details(UnitType unitType, UnitType secondType);
  void clear_unit_side_details();
  void show_victory();
  void show_defeat();
  /*************************************************/

  void tick();
};

#endif //TALLERZ_VISTA_H
