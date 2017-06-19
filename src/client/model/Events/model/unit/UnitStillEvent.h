#ifndef TALLERZ_UNITSTOPATTACKEVENT_H
#define TALLERZ_UNITSTOPATTACKEVENT_H

#include <client/model/Events/Event.h>

class UnitStillEvent : public Event {
 private:
  UnitID id;
  Position pos;
 public:
  UnitStillEvent(const UnitID &id, const Position &pos);
  void process();
};

#endif //TALLERZ_UNITSTOPATTACKEVENT_H
