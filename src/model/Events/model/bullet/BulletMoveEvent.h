#ifndef TALLERZ_BULLETMOVEEVENT_H
#define TALLERZ_BULLETMOVEEVENT_H

#include <model/Events/Event.h>

class BulletMoveEvent  : public Event {
 private:
  BulletID id;
  const Position posTo;

 public:
  BulletMoveEvent(const Bullet &bullet);
  virtual void process();
};

#endif //TALLERZ_BULLETMOVEEVENT_H