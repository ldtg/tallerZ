#ifndef TALLERZ_BULLETMOVESTEPEVENT_H
#define TALLERZ_BULLETMOVESTEPEVENT_H

#include <client/model/Events/Event.h>

class BulletMoveStepEvent : public Event {
 private:
  BulletID id;
  Position posTo;

 public:
  BulletMoveStepEvent(BulletID id, Position &posTo);
  virtual void process();
};

#endif //TALLERZ_BULLETMOVESTEPEVENT_H
