#ifndef TALLERZ_GAMECONTROLLERPROXY_H
#define TALLERZ_GAMECONTROLLERPROXY_H

#include <common/Map/Position.h>
#include <common/IDs/UnitID.h>
#include <common/IDs/BuildID.h>
#include <common/IDs/TerrainObjectID.h>
#include <common/IDs/CapturableID.h>
class GameControllerProxy {
 public:
  void move(const UnitID &unit, const Position &position);
  void attack(const UnitID &attacker, const UnitID &attacked);
  void attack(const UnitID &attacker, const BuildID &attacked);
  void attack(const UnitID &attacker, const TerrainObjectID &attacked);
  void changeUnitFab(const BuildID &buildId, const UnitType &type);
  void capture(const UnitID &unit, const CapturableID &capturable);
};

#endif //TALLERZ_GAMECONTROLLERPROXY_H
