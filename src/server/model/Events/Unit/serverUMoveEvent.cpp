#include <cereal/archives/binary.hpp>
#include "serverUMoveEvent.h"
serverUMoveEvent::serverUMoveEvent(const UnitID &id, const Position &pos)
    : serverEvent(U_MOVE), data(id, pos) {}
std::stringstream serverUMoveEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
