#ifndef TALLERZ_BULLETNEWEVENT_H
#define TALLERZ_BULLETNEWEVENT_H

#include <client/model/Events/Event.h>

class BulletNewEvent : public Event {
 private:
  BulletID id;
  WeaponType weapon;
  Position from;
  Position to;

 public:
  BulletNewEvent(const BulletID &bullet, const WeaponType &weaponType, const Position &from, const Position &to);
  virtual void process();
};

#endif //TALLERZ_BULLETNEWEVENT_H
