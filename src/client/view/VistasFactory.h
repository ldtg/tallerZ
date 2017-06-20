#ifndef TALLERZ_VISTASFACTORY_H
#define TALLERZ_VISTASFACTORY_H

#include <common/Types/UnitType.h>
#include <common/Types/WeaponType.h>
#include <common/Types/BuildType.h>
#include <common/Types/TerrainType.h>
#include <common/Types/CapturableType.h>
#include <common/Types/TerrainObjectType.h>
#include "Sprite.h"
#include "EffectType.h"
#include "Image.h"
#include "UnitView.h"

class VistasFactory {
 public:
  static ObjectMapaVista *getTerrainVista(TerrainType type, Position &pos);
  static UnitView *getUnitView(UnitType type, std::string &color,
                              std::string &action, std::string &rotation,
                              const Position &pos);
  static Sprite *getUnitVista(UnitType type, std::string &color,
                              std::string &action, std::string &rotation,
                              const Position &pos);
  static Sprite *getVehicleTopVista(UnitType type, std::string &color,
                              const Position &pos);
  static Sprite *getVehicleTopStillVista(UnitType type, std::string &color,
                                         const std::string &rotation, const Position &pos);
  static Image *getBuildVista(BuildType type, std::string &state, Position &pos);
  static ObjectMapaVista *getTerrainObjectVista(TerrainObjectType type,
                                                std::string &state, Position &pos);
  static Sprite *getFlagsVista(std::string &color, Position &pos);
  static Sprite *getBulletVista(WeaponType type, std::string &rotation, const Position &pos);
  static Sprite *getBulletHitVista(WeaponType type, Position &pos);
  static Sprite *getEffectVista(EffectType type);
};

#endif //TALLERZ_VISTASFACTORY_H
