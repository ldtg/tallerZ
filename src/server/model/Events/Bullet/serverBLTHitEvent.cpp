#include <cereal/archives/binary.hpp>
#include "serverBLTHitEvent.h"

serverBLTHitEvent::serverBLTHitEvent(const BulletID &id,
                                     const Position &pos,
                                     WeaponType weapon)
    : serverEvent(BLT_HIT), data(id, pos, weapon) {}
std::stringstream serverBLTHitEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
