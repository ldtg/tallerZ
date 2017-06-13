#include "UnitStillEvent.h"

UnitStillEvent::UnitStillEvent(const UnitID &id)
    : id(id) {}

void UnitStillEvent::process() {
  Sprite* unitVista = view->getUnitVista(id);
  int rotation = unitVista->getRotation();
  Position pos = unitVista->getPos();
  std::string color = unitVista->getColor();

//  view->removeUnitVista(id);

  std::string rotation_s = std::to_string(rotation);
  std::string action("look_around");
  unitVista = VistasFactory::getUnitVista(id.getType(), color, action, rotation_s, pos);
  unitVista->setPos(pos);
  unitVista->setRotation(rotation);

//  view->addUnitVista(id, unitVista);
}
