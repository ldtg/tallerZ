#include "UnitMoveStepEvent.h"

UnitMoveStepEvent::UnitMoveStepEvent(UnitID id, Position &posTo, int rotation)
    : id(id), posToo(posTo), rotation(rotation) {}

void UnitMoveStepEvent::process() {
//  std::map<UnitID, ObjectMapaVista*> &unitsVista = view->getUnitsVista();
//  unitsVista.at(id)->setPos(posToo);

  std::map<UnitID, ObjectMapaVista*> &unitsVista = view->getUnitsVista();
  int oldRotation = unitsVista.at(id)->getRotation();

  if (oldRotation != rotation) {
//  unitsVista.erase(id);
    view->removeUnitVista(id);

    std::string rotation_s = std::to_string(rotation);
    ObjectMapaVista *unitVista = view->getUnitVista(id.getType(), rotation_s);
    unitVista->setPos(posToo);
    unitVista->setRotation(rotation);

    view->addUnitVista(id, unitVista);
//  unitsVista.emplace(id, unitVista);
  }
  else {
    unitsVista.at(id)->setPos(posToo);
  }

}
