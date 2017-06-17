#include "UnitStillEvent.h"

UnitStillEvent::UnitStillEvent(const UnitID &id)
    : id(id) {}

void UnitStillEvent::process() {
  UnitView *unitView = view->getUnitView(id);
  unitView->still();
}
