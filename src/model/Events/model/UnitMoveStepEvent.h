#ifndef TALLERZ_UNITMOVESTEPEVENT_H
#define TALLERZ_UNITMOVESTEPEVENT_H

#include <model/Events/Event.h>

class UnitMoveStepEvent  : public Event {
 private:
//  Position posFrom;
  Position posToo;
  UnitID id;
  int rotation;
//  UnitState newState;
 public:
  UnitMoveStepEvent(UnitID id, Position &posTo, int rotation);
  void process();
};

#endif //TALLERZ_UNITMOVESTEPEVENT_H
