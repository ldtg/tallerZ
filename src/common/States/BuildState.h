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
  BuildState(const PlayerID &owner, const Position &pos, unsigned short health,
             unsigned short timeRemainingInSecs,
             const UnitType &type);
  BuildState(){};
  template<class Archive>
  void serialize(Archive &archive){
    archive(owner,position, health, timeRemainingInSecs, actualUnitFab);
  }
};

#endif //TALLERZ_BUILDSTATE_H
