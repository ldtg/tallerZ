
#ifndef TALLERZ_CLIENTE_UNITDAMAGERECEIVEEVENT_H
#define TALLERZ_CLIENTE_UNITDAMAGERECEIVEEVENT_H

#include <client/model/Events/Event.h>
class UnitDamageReceiveEvent : public Event{
 private:
  UnitID id;
  UnitState state;
 public:
  UnitDamageReceiveEvent(UnitID id, UnitState state);
  virtual void process() override ;
};

#endif //TALLERZ_CLIENTE_UNITDAMAGERECEIVEEVENT_H
