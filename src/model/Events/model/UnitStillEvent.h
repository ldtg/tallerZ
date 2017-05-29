#ifndef TALLERZ_UNITSTOPATTACKEVENT_H
#define TALLERZ_UNITSTOPATTACKEVENT_H

#include <model/Events/Event.h>

class UnitStopAttackEvent : public Event {
 private:
  UnitID id;
 public:
  UnitStopAttackEvent(const UnitID &id);
  void process();
};

#endif //TALLERZ_UNITSTOPATTACKEVENT_H
