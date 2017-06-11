#ifndef TALLERZ_BUILDSTATE_H
#define TALLERZ_BUILDSTATE_H

#include <common/Map/Position.h>
#include <common/Types/UnitType.h>
#include "common/IDs/PlayerID.h"
struct BuildState {
 public:
  PlayerID owner;
  Position position;
  unsigned short health;
  unsigned short timeRemainingInSecs;
  UnitType actualUnitFab;
  std::vector<UnitType> fabricableUnits;
  BuildState(const PlayerID &owner, const Position &pos, unsigned short health,
             unsigned short timeRemainingInSecs,
             const UnitType &type, const std::vector<UnitType>& fabricableUnits);
  BuildState(){};
  void set_unit_to_build(UnitType unitType){
    this->actualUnitFab = unitType;
  }
  template<class Archive>
  void serialize(Archive &archive){
    archive(owner,position, health, timeRemainingInSecs, actualUnitFab);
  }
};

#endif //TALLERZ_BUILDSTATE_H
