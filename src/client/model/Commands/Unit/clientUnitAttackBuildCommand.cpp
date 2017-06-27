#include <cereal/archives/binary.hpp>
#include "clientUnitAttackBuildCommand.h"
clientUnitAttackBuildCommand::clientUnitAttackBuildCommand(const UnitID &attacker,
                                                           const BuildID &attacked)
    : ClientCommand(U_ATK_B), data(attacker, attacked) {}
std::stringstream clientUnitAttackBuildCommand::getDataToSend() {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
