#include "DataUnitMoveEvent.h"
DataUnitMoveEvent::DataUnitMoveEvent(const UnitID &id, const Position &pos)
    : id(id), posTo(pos) {}

