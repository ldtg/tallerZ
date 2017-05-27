#include <iostream>
#include "UnitMoveEvent.h"

UnitMoveEvent::UnitMoveEvent(UnitID id, Position posTo)
    : id(id), posTo(posTo) {}

void UnitMoveEvent::process() {
  std::map<UnitID, ObjectMapaVista*> &unitsVista = view->getUnitsVista();

/*
  Position pos_aux = unitsVista.at(id)->getPos();
  while (pos_aux != posTo) {
    pos_aux.move(posTo);
    unitsVista.at(id)->setPos(posTo);
  }
*/

  unitsVista.at(id)->setPos(posTo);
}
