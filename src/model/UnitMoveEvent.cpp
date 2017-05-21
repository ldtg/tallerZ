#include "UnitMoveEvent.h"

UnitMoveEvent::UnitMoveEvent(UnitID id, UnitState newState)
    : id(id), newState(newState) {}

void UnitMoveEvent::process(Map &map) const {
  map.removeUnit(id);
  map.addUnit(id, newState);
}

