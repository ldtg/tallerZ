#ifndef TALLERZ_UNITEVENT_H
#define TALLERZ_UNITEVENT_H

#include "UnitState.h"
#include "UnitID.h"
#include "model/Events/Event.h"

class UnitMoveEvent {//: public Event {
 private:
  UnitID id;
  UnitState newState;
 public:
  UnitMoveEvent(UnitID id, UnitState newState);
  void process();
};

#endif //TALLERZ_UNITEVENT_H
