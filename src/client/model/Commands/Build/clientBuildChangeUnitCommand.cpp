#include <cereal/archives/binary.hpp>
#include "clientBuildChangeUnitCommand.h"
clientBuildChangeUnitCommand::clientBuildChangeUnitCommand(const BuildID &id,
                                                           const UnitType &type)
    : clientCommand(B_CFAB_U), data(id, type) {}
std::stringstream clientBuildChangeUnitCommand::getDataToSend() {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
