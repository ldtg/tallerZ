#include <cereal/archives/binary.hpp>
#include "clientUnitMoveCommand.h"
clientUnitMoveCommand::clientUnitMoveCommand(const UnitID &id,
                                             const Position &pos)
    : clientCommand(U_MOVE_P), data(id, pos) {}
std::stringstream clientUnitMoveCommand::getDataToSend() {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
