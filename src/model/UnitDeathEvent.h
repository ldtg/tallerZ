#ifndef TALLERZ_UNITDEATHEVENT_H
#define TALLERZ_UNITDEATHEVENT_H

#include "UnitID.h"
#include "Event.h"
class UnitDeathEvent : public Event{
 private:
  UnitID id;
 public:
  UnitDeathEvent(UnitID id);
  virtual void process(Map &map) const override;
};

#endif //TALLERZ_UNITDEATHEVENT_H