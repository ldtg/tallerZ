#ifndef TALLERZ_UNITMOVESTEPEVENT_H
#define TALLERZ_UNITMOVESTEPEVENT_H

#include <client/model/Events/Event.h>

class UnitMoveStepEvent : public Event {
 private:
  Position posTo;
  UnitID id;
  int rotation;
 public:
  UnitMoveStepEvent(UnitID id, Position &posTo, int rotation);
  void process();
};

#endif //TALLERZ_UNITMOVESTEPEVENT_H
