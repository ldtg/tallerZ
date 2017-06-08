#include <cereal/archives/binary.hpp>
#include "clientUnitCaptureCommand.h"
clientUnitCaptureCommand::clientUnitCaptureCommand(const UnitID &id,
                                                   const CapturableID &cid)
    : clientCommand(U_CAPT_C), data(id, cid) {}
std::stringstream clientUnitCaptureCommand::getDataToSend() {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
