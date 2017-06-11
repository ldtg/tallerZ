#include <cereal/archives/binary.hpp>
#include "clientUnitAttackUnitCommand.h"

clientUnitAttackUnitCommand::clientUnitAttackUnitCommand(const UnitID &attacker,
                                                         const UnitID &attacked)
    : clientCommand(U_ATK_U), data(attacker, attacked) {

}
std::stringstream clientUnitAttackUnitCommand::getDataToSend() {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
