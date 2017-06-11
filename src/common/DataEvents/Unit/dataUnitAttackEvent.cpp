#include "dataUnitAttackEvent.h"

dataUnitAttackEvent::dataUnitAttackEvent(const UnitID &id,
                                         const Position &hpos,
                                         const Position &attpos)
    : attacker(id), huntedPos(hpos), attackerPos(attpos) {}
