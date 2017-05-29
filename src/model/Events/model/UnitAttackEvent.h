#ifndef TALLERZ_UNITATTACKEVENT_H
#define TALLERZ_UNITATTACKEVENT_H

#include "model/Events/Event.h"
class UnitAttackEvent : public Event {
 private:
  UnitID attacker;
 public:
  UnitAttackEvent(const UnitID &attacker);
  void process();
};

#endif //TALLERZ_UNITATTACKEVENT_H
