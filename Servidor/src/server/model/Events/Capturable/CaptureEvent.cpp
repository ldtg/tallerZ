#include <cereal/archives/binary.hpp>
#include <cereal/types/map.hpp>
#include "CaptureEvent.h"
CaptureEvent::CaptureEvent(const UnitID &capturer,
                                         const CapturableID &captured,
                                         const Position &capturedPosition,
                                         const std::map<BuildID,
                                                        BuildState> &capturedBuilds,
                                         const std::map<UnitID,
                                                        UnitState> &capturedUnits,
                                         bool capturerDissapear) : ServerEvent(C_CAPTURE),
                                                                   data(capturer,
                                                                        captured,
                                                                        capturedPosition,
                                                                        capturedBuilds,
                                                                        capturedUnits,
                                                                        capturerDissapear) {}
std::stringstream CaptureEvent::getDataToSend() const {
  std::stringstream out;
  cereal::BinaryOutputArchive oarchive(out);
  oarchive(data);
  return out;
}
