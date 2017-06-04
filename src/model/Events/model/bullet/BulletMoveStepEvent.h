#ifndef TALLERZ_BULLETMOVESTEPEVENT_H
#define TALLERZ_BULLETMOVESTEPEVENT_H

#include <Events/Event.h>

class BulletMoveStepEvent : public Event {
 private:
  BulletID id;
  const Position posTo;

 public:
  BulletMoveStepEvent(BulletID id, Position &posTo);
  virtual void process();
};

#endif //TALLERZ_BULLETMOVESTEPEVENT_H
