
#include <cereal/archives/binary.hpp>
#include "UnitDamageReceiveEvent.h"

UnitDamageReceiveEvent::UnitDamageReceiveEvent(const UnitID &id,
                                 const UnitState &state) : ServerEvent(
    U_DAMAGE), data(id, state) {}
std::stringstream UnitDamageReceiveEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}