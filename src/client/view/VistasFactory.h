#ifndef TALLERZ_VISTASFACTORY_H
#define TALLERZ_VISTASFACTORY_H

#include <server/model/UnitType.h>
#include <server/model/WeaponType.h>
#include <server/model/BuildType.h>
#include <server/model/TerrainType.h>
#include <server/model/CapturableType.h>
#include <server/model/TerrainObjectType.h>
#include "Sprite.h"
#include "EffectType.h"
#include "Image.h"


class VistasFactory {
 public:
  static ObjectMapaVista *getTerrainVista(TerrainType type, Position &pos);
  static Sprite *getUnitVista(UnitType type, std::string &color,
                              std::string &action, std::string &rotation,
                              const Position &pos);
  static ObjectMapaVista *getBuildVista(BuildType type, std::string &state, Position &pos);
//  static ObjectMapaVista *getCapturableVista(CapturableType type, Position &pos);
  static ObjectMapaVista *getTerrainObjectVista(TerrainObjectType type, Position &pos);
  static Sprite *getFlagsVista(std::string &color, Position &pos);
  static ObjectMapaVista *getBulletVista(WeaponType type, std::string &rotation, Position &pos);
  static Sprite *getBulletHitVista(WeaponType type, Position &pos);
  static Sprite *getEffectVista(EffectType type);
};

#endif //TALLERZ_VISTASFACTORY_H
