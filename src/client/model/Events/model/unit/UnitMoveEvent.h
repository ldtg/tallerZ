#ifndef TALLERZ_UNITEVENT_H
#define TALLERZ_UNITEVENT_H

#include "common/States/UnitState.h"
#include "common/IDs/UnitID.h"
#include "client/model/Events/Event.h"

class UnitMoveEvent : public Event {
 private:
  UnitID id;
  Position posTo;
 public:
  UnitMoveEvent(UnitID id, Position posTo);
  void process();
};

#endif //TALLERZ_UNITEVENT_H
