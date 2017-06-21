#include "DataCaptureEvent.h"
DataCaptureEvent::DataCaptureEvent(const UnitID &capturer,
                                   const CapturableID &captured,
                                   const Position &capturedPosition,
                                   const std::map<BuildID,
                                                  BuildState> &capturedBuilds,
                                   const std::map<UnitID,
                                                  UnitState> &capturedUnits,
                                   bool capturerDissapear)
    : capturer(capturer),
      captured(captured),
      capturedPosition(capturedPosition),
      capturedBuilds(capturedBuilds),
      capturedUnits(capturedUnits),
      capturerDissapear(capturerDissapear) {}
DataCaptureEvent::DataCaptureEvent() {}
