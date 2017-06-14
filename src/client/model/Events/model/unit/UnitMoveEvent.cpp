
#include "UnitMoveEvent.h"

UnitMoveEvent::UnitMoveEvent(UnitID id, Position posTo)
    : id(id), posTo(posTo) {}

void UnitMoveEvent::process() {
  view->move(id, posTo);

  Map &map = model->getMap();
  UnitState state = map.getUnitState(id);
  state.position = posTo;
  map.updateUnit(id, state);
}
