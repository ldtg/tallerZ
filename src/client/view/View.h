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
#include <client/view/ObjectView.h>
#include "Sprite.h"
#include "ViewFactory.h"
#include "Camera.h"
#include "client/view/unit/UnitView.h"
#include "client/view/bullet/BulletView.h"
#include "client/view/sounds/SoundPlayer.h"
#include <client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.h>

class View {
 private:
  Window window;
  Camera &camera;
  Menu * menu = nullptr;
  Side_Board * side_board = nullptr;
  EventHandler &eventHandler;
  std::string playerColor;
  bool _quit;
//  SoundPlayer soundPlayer;

  std::map<Position, Image*> terrainsVista;
  std::map<TerrainObjectID, Image*> terrainObjectsVista;
  std::map<BuildID, BuildingView*> buildsVista;
  std::map<UnitID, UnitView*> unitsVista;
  std::map<CapturableID, Sprite*> capturablesVista;
  std::map<BulletID, BulletView*> bulletsVista;
  std::vector<Sprite*> effectsVista;
  std::vector<ExplosionView*> explosionsVista;

  void createInitialTerrainView(const std::map<Position, Tile> &map);
  void createInitialTerrainObjectView(const std::map<TerrainObjectID,
                                      TerrainObjectState> &terrainObjects);
  void createInitialUnitView(const std::map<UnitID, UnitState> &units);
  void createInitialBuildingView(const std::map<BuildID, BuildState> &builds);
  void createInitialCapturableView(const std::map<CapturableID,
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

  Image* getTerrainObjectView(const TerrainObjectID &id) const;
  void removeTerrainObjectView(const TerrainObjectID &id);
  void addTerrainObjectView(const TerrainObjectID &id,
                            Image *terrainObjectView);

  UnitView *getUnitView(const UnitID &id) const;
  void removeUnitView(const UnitID &id);
  void addUnitView(const UnitID &id, UnitView *unitView);

  BulletView *getBulletView(const BulletID &id) const;
  void removeBulletView(const BulletID &id);
  void addBulletView(const BulletID &id, BulletView *bulletView);

  BuildingView *getBuildingView(const BuildID &id);
  void removeBuildView(const BuildID &id);
//  void addBuildView(const BuildID &id, Image *buildView);

  Sprite *getCapturedView(const CapturableID &id);
  void addCapturableView(const CapturableID &id,
                         Sprite *capturableView);
  void removeCapturableView(const CapturableID &id);

  void addExplosionView(ExplosionView *explosionView);
  void addEffectView(Sprite *effectView);

//  SoundPlayer& getSoundPlayer();

  Menu *get_present_menu();
  void load_production_menu(const BuildID& factoryID,
                            const BuildState& buildState,
                            Model& model, int x, int y);
  void load_quit_menu();
  Side_Board * get_side_board();
  void free_menu();
  void show_unit_side_details(UnitType unitType, UnitType secondType, unsigned short health);
  void clear_unit_side_details();
  void show_victory();
  void show_defeat();

  void tick();
};

#endif //TALLERZ_VISTA_H
