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
#include "client/view/unit/UnitView.h"
#include "client/view/explosion/ExplosionView.h"
#include "client/view/building/BuildingView.h"
#include "client/view/building/BuildingEffectType.h"

class ViewFactory {
 public:
  static Image *getTerrainVista(const TerrainType &type,
                                const Position &pos);

  static UnitView *getUnitView(const UnitType &type,
                               const std::string &color,
                               std::string &action,
                               const std::string &rotation,
                               const Position &pos);
  static Sprite *getUnitAnimation(const UnitType &type,
                                  const std::string &color,
                                  std::string &action,
                                  const std::string &rotation,
                                  const Position &pos);

  static Sprite *getVehicleTopVista(const UnitType &type,
                                    const std::string &color,
                                    const Position &pos);
  static Sprite *getVehicleTopFireVista(const UnitType &type,
                                        const std::string &color,
                                        const std::string &rotation,
                                        const Position &pos);

  static BuildingView *getBuildingVista(const BuildType &type,
                                 const std::string &color,
                                 const Position &pos);
  static Image *getBuildingImage(const BuildType &type,
                                 const std::string &state,
                                 const Position &pos);
  static Sprite *getBuildingEffectView(const BuildingEffectType &type,
                                       const std::string &factoryType,
                                       const Position &pos);

  static Image *getTerrainObjectVista(const TerrainObjectType &type,
                                      const std::string &state,
                                      const Position &pos);
  static Sprite *getFlagsVista(const std::string &color,
                               const Position &pos);

  static Sprite *getBulletVista(const WeaponType &type,
                                const Position &pos);
  static ExplosionView *getBulletHitVista(const WeaponType &type,
                                          const Position &pos);

  static Sprite *getEffectVista(const EffectType &type,
                                const Position &pos);
};

#endif //TALLERZ_VISTASFACTORY_H
