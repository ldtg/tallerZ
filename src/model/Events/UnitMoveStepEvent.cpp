#include "UnitMoveStepEvent.h"

UnitMoveStepEvent::UnitMoveStepEvent(UnitID id, Position &posTo)
    : id(id), posToo(posTo) {}

void UnitMoveStepEvent::process() {
  std::map<UnitID, ObjectMapaVista*> &unitsVista = view->getUnitsVista();
  unitsVista.at(id)->setPos(posToo);
}
