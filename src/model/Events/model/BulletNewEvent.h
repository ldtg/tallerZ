#ifndef TALLERZ_BULLETNEWEVENT_H
#define TALLERZ_BULLETNEWEVENT_H

#include <model/Events/Event.h>
class BulletNewEvent : public Event{
 private:
  const BulletID id;
  const Weapon weapon;
  const Position from;
  const Position to;
 public:
  BulletNewEvent(const Bullet &bullet);
  virtual void process();
};

#endif //TALLERZ_BULLETNEWEVENT_H