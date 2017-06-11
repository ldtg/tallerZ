#ifndef TALLERZ_UNITATTACKEVENT_H
#define TALLERZ_UNITATTACKEVENT_H

#include "client/model/Events/Event.h"
class UnitAttackEvent : public Event {
 private:
  UnitID attacker;
  Position huntedPos;
  Position attackerPos;
 public:
  UnitAttackEvent(const UnitID &attacker, Position huntedPos, Position attackerPos);
  void process();
};

#endif //TALLERZ_UNITATTACKEVENT_H
