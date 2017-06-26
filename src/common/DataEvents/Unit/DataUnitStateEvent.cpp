#include "DataUnitStateEvent.h"
DataUnitStateEvent::DataUnitStateEvent(const UnitID &id,
                                         const UnitState &state)
    : id(id), state(state) {}
