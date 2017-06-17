#include "UnitMoveStepEvent.h"

UnitMoveStepEvent::UnitMoveStepEvent(UnitID id, Position &posTo, int rotation)
    : id(id), posTo(posTo), rotation(rotation) {}

void UnitMoveStepEvent::process() {
/*
  Sprite* unitVista = view->getUnitVista(id);
  int oldRotation = unitVista->getRotation();

  if (oldRotation != rotation) {
    std::string color = unitVista->getColor();

    view->removeUnitVista(id);

    std::string rotation_s = std::to_string(rotation);
    std::string action("walk");
    unitVista = VistasFactory::getUnitVista(id.getType(), color,
                                            action, rotation_s, posTo);
//    unitVista->setPos(posToo);
    unitVista->setRotation(rotation);

    view->addUnitVista(id, unitVista);
  }
  else {
    unitVista->setPos(posTo);
  }
*/
}
