#include <cereal/archives/binary.hpp>
#include "TerrainObjectDestroyedEvent.h"

TerrainObjectDestroyedEvent::TerrainObjectDestroyedEvent(const TerrainObjectID &id)
    : ServerEvent(TO_DESTROYED), data(id) {}

std::stringstream TerrainObjectDestroyedEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
