#ifndef TALLERZ_SERVERCCAPTUREEVENT_H
#define TALLERZ_SERVERCCAPTUREEVENT_H

#include <server/model/Events/ServerEvent.h>
#include <common/DataEvents/Capturable/DataCaptureEvent.h>
class CaptureEvent : public ServerEvent{
 private:
  DataCaptureEvent data;
 public:
  CaptureEvent(const UnitID &capturer,
                      const CapturableID &captured,
                      const Position &capturedPosition,
                      const std::map<BuildID, BuildState> &capturedBuilds,
                      const std::map<UnitID, UnitState> &capturedUnits,
                      bool capturerDissapear);
  virtual std::stringstream getDataToSend() const;

};

#endif //TALLERZ_SERVERCCAPTUREEVENT_H
