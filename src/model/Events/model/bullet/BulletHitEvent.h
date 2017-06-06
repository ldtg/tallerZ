#ifndef TALLERZ_BULLETHITEVENT_H
#define TALLERZ_BULLETHITEVENT_H

#include <Events/Event.h>
#include "BulletID.h"
#include "Position.h"
#include "Bullet.h"

class BulletHitEvent : public Event{
 private:
  BulletID id;
  Position pos;
  Weapon weapon;

 public:
  BulletHitEvent(const Bullet &bullet);
  virtual void process();
};

#endif //TALLERZ_BULLETHITEVENT_H
