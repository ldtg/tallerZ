#include "UnitMoveEvent.h"

UnitMoveEvent::UnitMoveEvent(UnitID id, UnitState newState)
    : id(id), newState(newState) {}

void UnitMoveEvent::process() {
//  map.removeUnit(id);
//  map.addUnit(id, newState);
}
