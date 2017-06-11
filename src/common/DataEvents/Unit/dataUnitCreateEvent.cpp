#include "dataUnitCreateEvent.h"
dataUnitCreateEvent::dataUnitCreateEvent(const UnitID &id,
                                         const UnitState &state)
    : id(id), state(state) {}
