#include "BuildState.h"
BuildState::BuildState(const PlayerID &owner,
                       const Position &pos,
                       unsigned short health,
                       unsigned short techLevel,
                       unsigned short timeRemainingInSecs,
                       const UnitType &type,
                       const std::vector<UnitType>& fabricableUnits)
    : owner(owner), position(pos), health(health),techLevel(techLevel),
      timeRemainingInSecs(timeRemainingInSecs),
      actualUnitFab(type), fabricableUnits(fabricableUnits) {

}
