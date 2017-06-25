#include "DataUnitAttackEvent.h"

DataUnitAttackEvent::DataUnitAttackEvent(const UnitID &id,
                                         const Position &hpos,
                                         const Position &attpos)
    : attacker(id), huntedPos(hpos), attackerPos(attpos) {}
