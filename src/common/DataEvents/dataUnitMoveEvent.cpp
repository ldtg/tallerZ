#include "dataUnitMoveEvent.h"
#include <cereal/archives/binary.hpp>
dataUnitMoveEvent::dataUnitMoveEvent(const UnitID &id, const Position &pos) : id(id), posTo(pos) {}
//dataUnitMoveEvent::dataUnitMoveEvent() : id(R_GRUNT), posTo(0, 0) {}
std::stringstream dataUnitMoveEvent::getStream() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(*this);
  return out;
}
dataUnitMoveEvent::dataUnitMoveEvent(std::stringstream &ss) : id(R_GRUNT){
  cereal::BinaryInputArchive iarchive(ss);
  iarchive(*this);
}
