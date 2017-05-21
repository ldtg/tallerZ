#ifndef TALLERZ_UNITATTACKEVENT_H
#define TALLERZ_UNITATTACKEVENT_H

#include "model/Events/Event.h"
class UnitAttackEvent : public Event{
 private:
  UnitID attacker;
  Position attackPosition;
 public:
  UnitAttackEvent(const UnitID &attacker,const Position &attackPos);
  virtual void process(Map &map) const override;

};

#endif //TALLERZ_UNITATTACKEVENT_H
