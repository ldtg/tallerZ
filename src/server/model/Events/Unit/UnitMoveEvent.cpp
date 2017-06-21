#include <cereal/archives/binary.hpp>
#include "UnitMoveEvent.h"
UnitMoveEvent::UnitMoveEvent(const UnitID &id, const Position &pos)
    : ServerEvent(U_MOVE), data(id, pos) {}
std::stringstream UnitMoveEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
