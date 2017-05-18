#include "UnitAttackEvent.h"
UnitAttackEvent::UnitAttackEvent(const UnitID &attacker,
                                 const Position &attackPos)
    : attacker(attacker), attackPosition(attackPos) {}
void UnitAttackEvent::process(Map &map) const {
  //Deberia impactar en el mapa?
}
