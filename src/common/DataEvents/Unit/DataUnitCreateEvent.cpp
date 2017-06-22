#include "DataUnitCreateEvent.h"
DataUnitCreateEvent::DataUnitCreateEvent(const UnitID &id,
                                         const UnitState &state)
    : id(id), state(state) {}
