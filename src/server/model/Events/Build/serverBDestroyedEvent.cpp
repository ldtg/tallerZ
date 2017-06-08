#include <cereal/archives/binary.hpp>
#include "serverBDestroyedEvent.h"
serverBDestroyedEvent::serverBDestroyedEvent(const BuildID &id) : serverEvent(
    B_DESTROYED), data(id) {}
std::stringstream serverBDestroyedEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
