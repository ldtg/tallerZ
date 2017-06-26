#include "UnitDamageReceiveEvent.h"
UnitDamageReceiveEvent::UnitDamageReceiveEvent(UnitID id, UnitState state)
    : id(id), state(state) {}

void UnitDamageReceiveEvent::process() {
  model->getMap().updateUnit(id, state);
}

