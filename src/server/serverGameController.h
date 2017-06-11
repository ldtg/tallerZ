#ifndef TALLERZ_SERVERGAMECONTROLLER_H
#define TALLERZ_SERVERGAMECONTROLLER_H

#include <common/IDs/CapturableID.h>
#include <common/IDs/UnitID.h>
#include <common/IDs/BuildID.h>
#include <common/IDs/TerrainObjectID.h>
#include <common/Map/Position.h>
class serverGameController {
 public:
  virtual void move(const UnitID &unit, const Position &position) = 0;
  virtual void attack(const UnitID &attacker, const UnitID &attacked)= 0;
  virtual void attack(const UnitID &attacker, const BuildID &attacked)= 0;
  virtual void attack(const UnitID &attacker,
                      const TerrainObjectID &attacked) = 0;
  virtual void changeUnitFab(const BuildID &buildId, const UnitType &type)= 0;
  virtual void capture(const UnitID &unit, const CapturableID &capturable)= 0;
  virtual void tick() = 0;
};

#endif //TALLERZ_SERVERGAMECONTROLLER_H
