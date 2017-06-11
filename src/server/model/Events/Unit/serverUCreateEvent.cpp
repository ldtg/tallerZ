#include <cereal/archives/binary.hpp>
#include "serverUCreateEvent.h"
serverUCreateEvent::serverUCreateEvent(const UnitID &id,
                                       const UnitState &state) : serverEvent(
    U_CREATE), data(id, state) {}
std::stringstream serverUCreateEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
