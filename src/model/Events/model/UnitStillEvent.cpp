#include "UnitStillEvent.h"

UnitStopAttackEvent::UnitStopAttackEvent(const UnitID &id)
    : id(id) {}

void UnitStopAttackEvent::process() {
  ObjectMapaVista* unitVista = view->getUnitVista(id);
  int rotation = unitVista->getRotation();
  Position pos = unitVista->getPos();

  view->removeUnitVista(id);

  std::string rotation_s = std::to_string(rotation);
  std::string action("look_around");
  unitVista = view->getUnitVista(id.getType(), action, rotation_s, 3);
  unitVista->setPos(pos);
  unitVista->setRotation(rotation);

  view->addUnitVista(id, unitVista);
}
