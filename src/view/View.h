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
  std::map<UnitID, ObjectMapaVista*> unitsVista;
  EventHandler &eventHandler;
  bool _quit;

  void createInitialTerrainVista(const std::map<Position, Tile> &map);
  void createInitialUnitVista(const std::map<UnitID, UnitState> &units);
  void add(ObjectMapaVista *objectVista, Position pos);
  ObjectMapaVista *getTerrainVista(TerrainType type);
  void draw();

 public:
  View(const Map &map, EventHandler &eventHandler, Window& window);
  ~View();
//  void setEventHandler(EventHandler &eventHandler);
  std::map<UnitID, ObjectMapaVista*> &getUnitsVista();

  void setQuit();
  bool quit();

  ObjectMapaVista *getUnitVista(UnitType type, std::string &rotation);
  void move(UnitID id, Position posTo);
  void removeUnitVista(UnitID &id);
  void addUnitVista(UnitID &id, ObjectMapaVista *unitVista);

  void update();
};


#endif //TALLERZ_VISTA_H
