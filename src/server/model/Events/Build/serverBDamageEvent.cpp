#include <cereal/archives/binary.hpp>
#include "serverBDamageEvent.h"
serverBDamageEvent::serverBDamageEvent(const BuildID &id,
                                       const BuildState &newState)
    : serverEvent(B_DAMAGE), data(id, newState) {
}
std::stringstream serverBDamageEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
