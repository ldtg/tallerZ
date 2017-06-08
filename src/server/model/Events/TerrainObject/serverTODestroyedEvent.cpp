#include <cereal/archives/binary.hpp>
#include "serverTODestroyedEvent.h"
serverTODestroyedEvent::serverTODestroyedEvent(const TerrainObjectID &id)
    : serverEvent(TO_DESTROYED), data(id) {}
std::stringstream serverTODestroyedEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
