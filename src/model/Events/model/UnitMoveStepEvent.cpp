#include "UnitMoveStepEvent.h"

UnitMoveStepEvent::UnitMoveStepEvent(UnitID id, Position &posTo, int rotation)
    : id(id), posToo(posTo), rotation(rotation) {}

void UnitMoveStepEvent::process() {
//  std::map<UnitID, ObjectMapaVista*> &unitsVista = view->getUnitsVista();
//  unitsVista.at(id)->setPos(posToo);

  ObjectMapaVista* unitVista = view->getUnitVista(id);
  int oldRotation = unitVista->getRotation();

  if (oldRotation != rotation) {
//  unitsVista.erase(id);
    view->removeUnitVista(id);

    std::string rotation_s = std::to_string(rotation);
    std::string action("walk");
    unitVista = view->getUnitVista(id.getType(), action,rotation_s);
    unitVista->setPos(posToo);
    unitVista->setRotation(rotation);

    view->addUnitVista(id, unitVista);
//  unitsVista.emplace(id, unitVista);
  }
  else {
//    if (id.getType() == V_JEEP) {
//      unitVista->setPos(posToo.sub(25, 25));
//    } else {
//      unitVista->setPos(posToo.sub(8, 8));
//    }
    unitVista->setPos(posToo);
  }

}
