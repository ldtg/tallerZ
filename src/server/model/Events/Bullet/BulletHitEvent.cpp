#include <cereal/archives/binary.hpp>
#include "BulletHitEvent.h"

BulletHitEvent::BulletHitEvent(const BulletID &id,
                                     const Position &pos,
                                     WeaponType weapon)
    : ServerEvent(BLT_HIT), data(id, pos, weapon) {}
std::stringstream BulletHitEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
