#ifndef TALLERZ_DAMAGERECEIVEEVENT_H
#define TALLERZ_DAMAGERECEIVEEVENT_H

#include "Event.h"
class UnitDamageReceiveEvent : public Event {
 private:
  UnitID id;
  UnitState newState;
 public:
  UnitDamageReceiveEvent(UnitID id, UnitState newState);
  virtual void process(Map &map) const override;
};

#endif //TALLERZ_DAMAGERECEIVEEVENT_H
