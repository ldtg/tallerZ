#ifndef TALLERZ_VISTA_H
#define TALLERZ_VISTA_H

#include "../model/Map.h"
#include "Window.h"
#include "Panel.h"
#include <string>

class Vista {
 private:
  Window window;
  Panel panel;
  std::map<Position, ObjectMapaVista*> terrainsVista;
  std::map<Position, ObjectMapaVista*> unitsVista;

  void createInitialTerrainVista(const std::map<Position, Tile> &map);
  void createInitialUnitVista(const std::map<UnitID, UnitState> &units);
  void add(ObjectMapaVista *objectVista, long x, long y);
  ObjectMapaVista *getTerrainVista(int type);
  ObjectMapaVista *getUnitVista(int type);
 public:
  Vista(const Map &map);
  ~Vista();
  void update();
};


#endif //TALLERZ_VISTA_H
