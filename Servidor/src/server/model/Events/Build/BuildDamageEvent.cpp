#include <cereal/archives/binary.hpp>
#include "BuildDamageEvent.h"
BuildDamageEvent::BuildDamageEvent(const BuildID &id,
                                       const BuildState &newState)
    : ServerEvent(B_DAMAGE), data(id, newState) {
}
std::stringstream BuildDamageEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
