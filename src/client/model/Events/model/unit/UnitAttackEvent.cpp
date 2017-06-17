#include <client/view/Sprite.h>
#include <client/view/VistasFactory.h>
#include "UnitAttackEvent.h"

UnitAttackEvent::UnitAttackEvent(const UnitID &attacker, Position huntedPos,
                                 Position attackerPos)
    : attacker(attacker), huntedPos(huntedPos), attackerPos(attackerPos) {}

void UnitAttackEvent::process() {
  UnitView *attackerView = view->getUnitView(attacker);
  attackerView->fire(huntedPos);

/*
  Sprite* unitVista = view->getUnitVista(attacker);
  Position pos = unitVista->getPos();
  std::string color = unitVista->getColor();


  int rotation = attackerPos.getRoration(huntedPos);
  std::string rotation_s = std::to_string(rotation);
  std::string action("fire");
  UnitView unitAttackerVista(attacker.getType(), color, pos, action, rotation_s);

  unitVista->setRotation(rotation);
  view->removeUnitVista(attacker);
  view->addUnitVista(attacker, unitAttackerVista);
*/
}
