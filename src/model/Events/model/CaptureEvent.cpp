#include "CaptureEvent.h"
CaptureEvent::CaptureEvent(const UnitID &capturer,
                           const std::map<BuildID, BuildState> &capturedBuilds,
                           const std::map<UnitID, UnitState> &capturedUnits,
                           bool dissapear)
    : capturer(capturer),
      capturedBuilds(capturedBuilds),
      capturedUnits(capturedUnits),
      capturerDissapear(dissapear) {

}
void CaptureEvent::process() {

}
