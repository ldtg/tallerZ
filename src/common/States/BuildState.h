#ifndef TALLERZ_BUILDSTATE_H
#define TALLERZ_BUILDSTATE_H

#include "UnitType.h"
#include "Position.h"
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
};

#endif //TALLERZ_BUILDSTATE_H
