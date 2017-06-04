#ifndef TALLERZ_VISTA_H
#define TALLERZ_VISTA_H

class EventHandler;

#include "../model/Map.h"
#include "Window.h"
#include "Panel.h"
#include <string>
#include "../model/Events/EventHandler.h"
#include "Sprite.h"
#include "VistasFactory.h"
#include "Camera.h"

class View {
 private:
  Window window;
  Camera &camera;
  Panel panel;
  EventHandler &eventHandler;
  bool _quit;

  std::map<Position, ObjectMapaVista*> terrainsVista;
  std::map<BuildID, ObjectMapaVista*> buildsVista;
  std::map<UnitID, Sprite*> unitsVista;
  std::map<BulletID, ObjectMapaVista*> bulletsVista;
  std::vector<Sprite*> explosionsVista;

  void createInitialTerrainVista(const std::map<Position, Tile> &map);
  void createInitialUnitVista(const std::map<UnitID, UnitState> &units);
  void createInitialBuildVista(const std::map<BuildID, BuildState> &builds);

//  void add(ObjectMapaVista *objectVista, Position pos);
//  ObjectMapaVista *getTerrainVista(TerrainType type);
//  void updateExplosion();
  void drawSteps();
  void draw();

 public:
  View(const Map &map, EventHandler &eventHandler, Camera &camera);
  ~View();
//  void setEventHandler(EventHandler &eventHandler);
  void add(ObjectMapaVista *objectVista, Position pos);

  Position translateModelPos(UnitType type, std::string &action, Position pos);
  void moveCamera(int x, int y);

  void setQuit();
  bool quit();

  Sprite* getUnitVista(UnitID id);
//  Sprite *getUnitVista(UnitType type, std::string &action,
//                                std::string &rotation);
  void move(UnitID id, Position posTo);
  void removeUnitVista(UnitID &id);
  void addUnitVista(UnitID &id, Sprite *unitVista);

  ObjectMapaVista* getBulletVista(BulletID id);
//  ObjectMapaVista *getBulletVista(WeaponType type);
  void move(BulletID id, Position posTo);
  void removeBulletVista(BulletID &id);
  void addBulletVista(BulletID &id, ObjectMapaVista *bulletVista);

  ObjectMapaVista* getBuildVista(BuildID id);
//  ObjectMapaVista *getBuildVista(BuildType type, std::string &state);
  void removeBuildVista(BuildID &id);
  void addBuildVista(BuildID &id, ObjectMapaVista *buildVista);

  void addExplosionVista(Sprite *objectVista, Position pos);

  void update();
};


#endif //TALLERZ_VISTA_H
