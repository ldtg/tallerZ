#ifndef TALLERZ_CAPTUREEVENT_H
#define TALLERZ_CAPTUREEVENT_H

#include <model/Events/Event.h>
class CaptureEvent : public Event {
 private:
  UnitID capturer;
  std::map<BuildID, BuildState> capturedBuilds;
  std::map<UnitID, UnitState> capturedUnits;
  bool capturerDissapear;
 public:
  CaptureEvent(const UnitID &capturer, const std::map<BuildID, BuildState> &capturedBuilds,const std::map<UnitID, UnitState> &capturedUnits, bool dissapear);
  virtual void process() override;
};

#endif //TALLERZ_CAPTUREEVENT_H
