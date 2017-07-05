#include <cereal/archives/binary.hpp>
#include "UnitDeathEvent.h"
UnitDeathEvent::UnitDeathEvent(const UnitID &id) :ServerEvent(U_DEATH), data(id){}
std::stringstream UnitDeathEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
