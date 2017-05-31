#ifndef TALLERZ_VISTA_H
#define TALLERZ_VISTA_H

class EventHandler;

#include "../model/Map.h"
#include "Window.h"
#include "Panel.h"
#include <string>
#include "../model/Events/EventHandler.h"

class View {
 private:
  Window &window;
  Panel panel;
  std::map<Position, ObjectMapaVista*> terrainsVista;
  std::map<BuildID, ObjectMapaVista*> buildsVista;
  std::map<UnitID, ObjectMapaVista*> unitsVista;
  std::map<BulletID, ObjectMapaVista*> bulletsVista;
  std::vector<ObjectMapaVista*> explosionsVista;
  EventHandler &eventHandler;
  bool _quit;

  void createInitialTerrainVista(const std::map<Position, Tile> &map);
  void createInitialUnitVista(const std::map<UnitID, UnitState> &units);
  void createInitialBuildVista(const std::map<BuildID, BuildState> &builds);

//  void add(ObjectMapaVista *objectVista, Position pos);
  ObjectMapaVista *getTerrainVista(TerrainType type);
  void updateExplosion();
  void draw();

 public:
  View(const Map &map, EventHandler &eventHandler, Window& window);
  ~View();
//  void setEventHandler(EventHandler &eventHandler);
  void add(ObjectMapaVista *objectVista, Position pos);

  Position translatePos(UnitType type, std::string &action, Position pos);

  void setQuit();
  bool quit();

  ObjectMapaVista* getUnitVista(UnitID id);
  ObjectMapaVista *getUnitVista(UnitType type, std::string &action,
                                std::string &rotation);
  void move(UnitID id, Position posTo);
  void removeUnitVista(UnitID &id);
  void addUnitVista(UnitID &id, ObjectMapaVista *unitVista);

  ObjectMapaVista* getBulletVista(BulletID id);
  ObjectMapaVista *getBulletVista(WeaponType type);
  void move(BulletID id, Position posTo);
  void removeBulletVista(BulletID &id);
  void addBulletVista(BulletID &id, ObjectMapaVista *bulletVista);

  ObjectMapaVista* getBuildVista(BuildID id);
  ObjectMapaVista *getBuildVista(BuildType type, std::string &state);
  void removeBuildVista(BuildID &id);
  void addBuildVista(BuildID &id, ObjectMapaVista *buildVista);

  void addExplosionVista(ObjectMapaVista *objectVista, Position pos);

  void update();
};


#endif //TALLERZ_VISTA_H
