#ifndef TALLERZ_UNITEVENT_H
#define TALLERZ_UNITEVENT_H

#include "UnitState.h"
#include "UnitID.h"
#include "client/model/Events/Event.h"

class UnitMoveEvent : public Event {
 private:
//  Position posFrom;
  Position posTo;
  UnitID id;
//  UnitState newState;
 public:
  UnitMoveEvent(UnitID id, Position posTo);
  void process();
};

#endif //TALLERZ_UNITEVENT_H
