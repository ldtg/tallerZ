#ifndef TALLERZ_UNITDEATHEVENT_H
#define TALLERZ_UNITDEATHEVENT_H

#include "UnitID.h"
#include "model/Events/Event.h"

class UnitDeathEvent {//: public Event{
 private:
  UnitID id;
 public:
  UnitDeathEvent(UnitID id);
  void process();
};

#endif //TALLERZ_UNITDEATHEVENT_H
