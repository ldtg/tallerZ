#ifndef TALLERZ_UNITCREATEEVENT_H
#define TALLERZ_UNITCREATEEVENT_H

#include <Events/Event.h>
class UnitCreateEvent : public Event{
 private:
  UnitID id;
  UnitState state;
 public:
  UnitCreateEvent(UnitID id, UnitState state);
  virtual void process() override ;
};

#endif //TALLERZ_UNITCREATEEVENT_H
