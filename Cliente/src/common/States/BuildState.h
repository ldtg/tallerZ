#ifndef TALLERZ_BUILDSTATE_H
#define TALLERZ_BUILDSTATE_H

#include <common/Map/Position.h>
#include <common/Types/UnitType.h>
#include "common/IDs/PlayerID.h"
#include <cereal/types/vector.hpp>
struct BuildState {
 public:
  PlayerID owner;
  Position position;
  unsigned short health;
  unsigned short techLevel;
  unsigned short timeRemainingInSecs;
  UnitType actualUnitFab;
  std::vector<UnitType> fabricableUnits;
  BuildState(const PlayerID &owner,
             const Position &pos,
             unsigned short health,
             unsigned short techLevel,
             unsigned short timeRemainingInSecs,
             const UnitType &type,
             const std::vector<UnitType> &fabricableUnits);
  BuildState() {};
  void set_unit_to_build(UnitType unitType) {
    this->actualUnitFab = unitType;
  }
  template<class Archive>
  void serialize(Archive &archive) {
    archive(owner,
            position,
            health,
            techLevel,
            timeRemainingInSecs,
            actualUnitFab,
            fabricableUnits);
  }
};

#endif //TALLERZ_BUILDSTATE_H
