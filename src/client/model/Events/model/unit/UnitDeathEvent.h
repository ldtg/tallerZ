#ifndef TALLERZ_UNITDEATHEVENT_H
#define TALLERZ_UNITDEATHEVENT_H

#include "common/IDs/UnitID.h"
#include "client/model/Events/Event.h"

class UnitDeathEvent : public Event{
 private:
  UnitID id;
 public:
  UnitDeathEvent(UnitID id);
  virtual void process();
};

#endif //TALLERZ_UNITDEATHEVENT_H
