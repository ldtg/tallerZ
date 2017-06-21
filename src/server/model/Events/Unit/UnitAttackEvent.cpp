#include <cereal/archives/binary.hpp>
#include "UnitAttackEvent.h"

UnitAttackEvent::UnitAttackEvent(const UnitID &id,
                                       const Position &hpos,
                                       const Position &attpos)
    : ServerEvent(U_ATTACK), data(id, hpos, attpos) {}

std::stringstream UnitAttackEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
