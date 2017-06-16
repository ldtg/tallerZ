#include "UnitStillEvent.h"

UnitStillEvent::UnitStillEvent(const UnitID &id)
    : id(id) {}

void UnitStillEvent::process() {
  Sprite* unitVista = view->getUnitVista(id);
  int rotation = unitVista->getRotation();
  Position pos = unitVista->getPos();
  std::string color = unitVista->getColor();


  std::string rotation_s = std::to_string(rotation);
  std::string action("look_around");
  UnitView unitStillVista(id.getType(), color, pos, action, rotation_s);
  unitVista->setPos(pos);
  unitVista->setRotation(rotation);
  view->removeUnitVista(id);

  view->addUnitVista(id, unitStillVista);
}
