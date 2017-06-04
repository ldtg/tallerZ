#ifndef TALLERZ_VISTASFACTORY_H
#define TALLERZ_VISTASFACTORY_H

#include <model/UnitType.h>
#include <model/WeaponType.h>
#include <model/BuildType.h>
#include <model/TerrainType.h>
#include "Sprite.h"
#include "EffectType.h"

class VistasFactory {
 public:
  static ObjectMapaVista *getTerrainVista(TerrainType type);
  static Sprite *getUnitVista(UnitType type,
                              std::string &color,
                              std::string &action,
                              std::string &rotation);
  static ObjectMapaVista *getBuildVista(BuildType type, std::string &state);
  static ObjectMapaVista *getBulletVista(WeaponType type, std::string &rotation);
  static Sprite *getEffectVista(EffectType type);
};

#endif //TALLERZ_VISTASFACTORY_H
