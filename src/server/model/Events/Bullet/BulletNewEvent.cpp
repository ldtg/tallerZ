#include <cereal/archives/binary.hpp>
#include "BulletNewEvent.h"
BulletNewEvent::BulletNewEvent(const BulletID &id,
                                     WeaponType weapon,
                                     const Position &from,
                                     const Position &to)
    : ServerEvent(BLT_NEW), data(id, weapon, from, to) {

}
std::stringstream BulletNewEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
