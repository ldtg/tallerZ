#include <cereal/archives/binary.hpp>
#include <cereal/types/map.hpp>
#include "serverCCaptureEvent.h"
serverCCaptureEvent::serverCCaptureEvent(const UnitID &capturer,
                                         const CapturableID &captured,
                                         const Position &capturedPosition,
                                         const std::map<BuildID,
                                                        BuildState> &capturedBuilds,
                                         const std::map<UnitID,
                                                        UnitState> &capturedUnits,
                                         bool capturerDissapear) : serverEvent(C_CAPTURE),
                                                                   data(capturer,
                                                                        captured,
                                                                        capturedPosition,
                                                                        capturedBuilds,
                                                                        capturedUnits,
                                                                        capturerDissapear) {}
std::stringstream serverCCaptureEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
