#ifndef TALLERZ_UNITMOVESTEPEVENT_H
#define TALLERZ_UNITMOVESTEPEVENT_H

#include <Events/Event.h>

class UnitMoveStepEvent : public Event {
 private:
//  Position posFrom;
  Position posTo;
  UnitID id;
  int rotation;
//  UnitState newState;
 public:
  UnitMoveStepEvent(UnitID id, Position &posTo, int rotation);
  void process();
};

#endif //TALLERZ_UNITMOVESTEPEVENT_H
