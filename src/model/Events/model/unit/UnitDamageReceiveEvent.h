#ifndef TALLERZ_DAMAGERECEIVEEVENT_H
#define TALLERZ_DAMAGERECEIVEEVENT_H

#include "Events/Event.h"
class UnitDamageReceiveEvent : public Event {
 private:
  UnitID id;
  UnitState newState;
 public:
  UnitDamageReceiveEvent(UnitID id, UnitState newState);
  void process();
};

#endif //TALLERZ_DAMAGERECEIVEEVENT_H
