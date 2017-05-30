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
    ObjectMapaVista *unitVista = view->getUnitVista(id.getType(), action,rotation_s);
    unitVista->setPos(posToo);
    unitVista->setRotation(rotation);

    view->addUnitVista(id, unitVista);
//  unitsVista.emplace(id, unitVista);
  }
  else {
    unitVista->setPos(posToo);
  }

}
