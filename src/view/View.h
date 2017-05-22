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
  Window window;
  Panel panel;
  std::map<Position, ObjectMapaVista*> terrainsVista;
  std::map<Position, ObjectMapaVista*> unitsVista;
  EventHandler &eventHandler;
  bool _quit;

  void createInitialTerrainVista(const std::map<Position, Tile> &map);
  void createInitialUnitVista(const std::map<UnitID, UnitState> &units);
  void add(ObjectMapaVista *objectVista, long x, long y);
  ObjectMapaVista *getTerrainVista(int type);
  ObjectMapaVista *getUnitVista(int type);
 public:
  View(const Map &map, EventHandler &eventHandler);
  ~View();
//  void setEventHandler(EventHandler &eventHandler);
  void setQuit();
  bool quit();
  void update();
};


#endif //TALLERZ_VISTA_H
