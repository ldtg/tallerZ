#include <cereal/archives/binary.hpp>
#include "serverBLTMoveEvent.h"
serverBLTMoveEvent::serverBLTMoveEvent(const BulletID &id,
                                       const Position &posTo) :serverEvent(BLT_MOVE), data(id,posTo){}
std::stringstream serverBLTMoveEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
