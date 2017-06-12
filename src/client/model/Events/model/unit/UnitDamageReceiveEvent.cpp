#include "UnitDamageReceiveEvent.h"

UnitDamageReceiveEvent::UnitDamageReceiveEvent(UnitID id, UnitState newState)
    : id(id), newState(newState) {
}

void UnitDamageReceiveEvent::process() {
//  map.removeUnit(id);
//  map.addUnit(id, newState);
}