#include "dataUnitStateEvent.h"
dataUnitStateEvent::dataUnitStateEvent(const UnitID &id,
                                         const UnitState &state)
    : id(id), state(state) {}
