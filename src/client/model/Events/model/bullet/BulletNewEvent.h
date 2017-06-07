#ifndef TALLERZ_BULLETNEWEVENT_H
#define TALLERZ_BULLETNEWEVENT_H

#include <client/model/Events/Event.h>

class BulletNewEvent : public Event {
 private:
  BulletID id;
  Weapon weapon;
  Position from;
  Position to;

 public:
  BulletNewEvent(const Bullet &bullet);
  virtual void process();
};

#endif //TALLERZ_BULLETNEWEVENT_H
