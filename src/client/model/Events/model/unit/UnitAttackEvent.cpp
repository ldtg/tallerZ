#include <client/view/Sprite.h>
#include <client/view/VistasFactory.h>
#include "UnitAttackEvent.h"

UnitAttackEvent::UnitAttackEvent(const UnitID &attacker, Position huntedPos,
                                 Position attackerPos)
    : attacker(attacker), huntedPos(huntedPos), attackerPos(attackerPos) {}

void UnitAttackEvent::process() {
  UnitView *attackerView = view->getUnitView(attacker);
  attackerView->fire(huntedPos);
}
