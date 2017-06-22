#include <cereal/archives/binary.hpp>
#include "BulletMoveEvent.h"
BulletMoveEvent::BulletMoveEvent(const BulletID &id,
                                       const Position &posTo) :ServerEvent(BLT_MOVE), data(id,posTo){}
std::stringstream BulletMoveEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
