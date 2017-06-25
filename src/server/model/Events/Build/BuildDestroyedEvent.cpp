#include <cereal/archives/binary.hpp>
#include "BuildDestroyedEvent.h"
BuildDestroyedEvent::BuildDestroyedEvent(const BuildID &id) : ServerEvent(
    B_DESTROYED), data(id) {}
std::stringstream BuildDestroyedEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
