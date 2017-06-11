#include <cereal/archives/binary.hpp>
#include "serverUAttackEvent.h"

serverUAttackEvent::serverUAttackEvent(const UnitID &id,
                                       const Position &hpos,
                                       const Position &attpos)
    : serverEvent(U_ATTACK), data(id, hpos, attpos) {}

std::stringstream serverUAttackEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
