#include <cereal/archives/binary.hpp>
#include "serverBLTNewEvent.h"
serverBLTNewEvent::serverBLTNewEvent(const BulletID &id,
                                     WeaponType weapon,
                                     const Position &from,
                                     const Position &to)
    : serverEvent(BLT_NEW), data(id, weapon, from, to) {

}
std::stringstream serverBLTNewEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
