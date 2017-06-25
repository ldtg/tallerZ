#include <cereal/archives/binary.hpp>
#include "UnitStillEvent.h"

UnitStillEvent::UnitStillEvent(const UnitID &id, const Position &pos) :ServerEvent(U_STILL), data(id,pos){}

std::stringstream UnitStillEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
