#include <cereal/archives/binary.hpp>
#include "serverUDeathEvent.h"
serverUDeathEvent::serverUDeathEvent(const UnitID &id) :serverEvent(U_DEATH), data(id){}
std::stringstream serverUDeathEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
