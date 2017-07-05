#include "UnitStillEvent.h"

UnitStillEvent::UnitStillEvent(const UnitID &id, const Position &pos)
    : id(id), pos(pos) {}

void UnitStillEvent::process() {
  UnitView *unitView = view->getUnitView(id);
  ViewPosition posView(pos.getX(), pos.getY());
  unitView->addMove(posView);
  unitView->setLastMove();
}
