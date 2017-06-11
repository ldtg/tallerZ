#ifndef TALLERZ_SERVERCCAPTUREEVENT_H
#define TALLERZ_SERVERCCAPTUREEVENT_H

#include <server/model/Events/serverEvent.h>
#include <common/DataEvents/Capturable/dataCaptureEvent.h>
class serverCCaptureEvent : public serverEvent{
 private:
  dataCaptureEvent data;
 public:
  serverCCaptureEvent(const UnitID &capturer,
                      const CapturableID &captured,
                      const Position &capturedPosition,
                      const std::map<BuildID, BuildState> &capturedBuilds,
                      const std::map<UnitID, UnitState> &capturedUnits,
                      bool capturerDissapear);
  virtual std::stringstream getDataToSend() const;

};

#endif //TALLERZ_SERVERCCAPTUREEVENT_H
