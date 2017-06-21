#include <cereal/archives/binary.hpp>
#include "UnitCreateEvent.h"
UnitCreateEvent::UnitCreateEvent(const UnitID &id,
                                       const UnitState &state) : ServerEvent(
    U_CREATE), data(id, state) {}
std::stringstream UnitCreateEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
