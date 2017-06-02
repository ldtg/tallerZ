#ifndef TALLERZ_VISTASFACTORY_H
#define TALLERZ_VISTASFACTORY_H

#include <model/UnitType.h>
#include <model/WeaponType.h>
#include <model/BuildType.h>
#include <model/TerrainType.h>
#include "Sprite.h"

class VistasFactory {
 public:
  ObjectMapaVista *getTerrainVista(TerrainType type);
  Sprite *getUnitVista(UnitType type,
                       std::string &action,
                       std::string &rotation);
  ObjectMapaVista *getBuildVista(BuildType type, std::string &state);
  ObjectMapaVista *getBulletVista(WeaponType type);
};

#endif //TALLERZ_VISTASFACTORY_H
