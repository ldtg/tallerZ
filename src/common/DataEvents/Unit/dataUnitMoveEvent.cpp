#include "dataUnitMoveEvent.h"
#include <cereal/archives/binary.hpp>
dataUnitMoveEvent::dataUnitMoveEvent(const UnitID &id, const Position &pos)
    : id(id), posTo(pos) {}

