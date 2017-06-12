#ifndef TALLERZ_CAPTUREEVENT_H
#define TALLERZ_CAPTUREEVENT_H

#include <client/model/Events/Event.h>

class CaptureEvent : public Event {
 private:
  UnitID capturer;
  CapturableID captured;
  Position capturedPosition;
  std::map<BuildID, BuildState> capturedBuilds;
  std::map<UnitID, UnitState> capturedUnits;
  bool capturerDissapear;

 public:
  CaptureEvent(const UnitID &capturer,
               const CapturableID &captured,
               const Position capturedPosition,
               const std::map<BuildID, BuildState> &capturedBuilds,
               const std::map<UnitID, UnitState> &capturedUnits,
               bool dissapear);
  virtual void process() override;
};

#endif //TALLERZ_CAPTUREEVENT_H
