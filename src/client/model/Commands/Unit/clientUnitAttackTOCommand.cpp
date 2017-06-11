#include <cereal/archives/binary.hpp>
#include "clientUnitAttackTOCommand.h"
clientUnitAttackTOCommand::clientUnitAttackTOCommand(const UnitID &attacker,
                                                     const TerrainObjectID &attacked)
    : clientCommand(U_ATK_TO), data(attacker, attacked) {

}
std::stringstream clientUnitAttackTOCommand::getDataToSend() {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
