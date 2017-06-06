#include "UnitAttackEvent.h"

UnitAttackEvent::UnitAttackEvent(const UnitID &attacker, Position huntedPos,
                                 Position attackerPos)
    : attacker(attacker), huntedPos(huntedPos), attackerPos(attackerPos) {}

void UnitAttackEvent::process() {
  Sprite* unitVista = view->getUnitVista(attacker);
  Position pos = unitVista->getPos();
  std::string color = unitVista->getColor();

  view->removeUnitVista(attacker);

  int rotation = attackerPos.getRoration(huntedPos);
  std::string rotation_s = std::to_string(rotation);
  std::string action("fire");
  unitVista = VistasFactory::getUnitVista(attacker.getType(), color, action, rotation_s, pos);
//  unitVista->setPos(pos);
  unitVista->setRotation(rotation);

  view->addUnitVista(attacker, unitVista);
}
