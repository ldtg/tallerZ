#include "BuildState.h"
BuildState::BuildState(const PlayerID &owner,
                       const Position &pos,
                       unsigned short health,
                       unsigned short timeRemainingInSecs,
                       const UnitType &type,
                       const std::vector<UnitType>& fabricableUnits)
    : owner(owner), position(pos), health(health),
      timeRemainingInSecs(timeRemainingInSecs),
      actualUnitFab(type), fabricableUnits(fabricableUnits) {

}
