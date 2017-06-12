#ifndef TALLERZ_UNITSTOPATTACKEVENT_H
#define TALLERZ_UNITSTOPATTACKEVENT_H

#include <client/model/Events/Event.h>

class UnitStillEvent : public Event {
 private:
  UnitID id;
 public:
  UnitStillEvent(const UnitID &id);
  void process();
};

#endif //TALLERZ_UNITSTOPATTACKEVENT_H
