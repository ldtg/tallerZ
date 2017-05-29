#include "UnitAttackEvent.h"

UnitAttackEvent::UnitAttackEvent(const UnitID &attacker)
    : attacker(attacker) {}

void UnitAttackEvent::process() {
  ObjectMapaVista* unitVista = view->getUnitVista(attacker);
  int rotation = unitVista->getRotation();
  Position pos = unitVista->getPos();

  view->removeUnitVista(attacker);

  std::string rotation_s = std::to_string(rotation);
  std::string action("fire");
  unitVista = view->getUnitVista(attacker.getType(), action, rotation_s, 5, 2);
  unitVista->setPos(pos);
  unitVista->setRotation(rotation);

  view->addUnitVista(attacker, unitVista);
}
