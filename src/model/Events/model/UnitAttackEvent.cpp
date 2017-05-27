#include "UnitAttackEvent.h"

UnitAttackEvent::UnitAttackEvent(const UnitID &attacker,
                                 const Position &attackPos)
    : attacker(attacker), attackPosition(attackPos) {}

void UnitAttackEvent::process() {
  //Deberia impactar en el mapa?
}
