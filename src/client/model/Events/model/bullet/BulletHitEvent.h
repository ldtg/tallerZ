#ifndef TALLERZ_BULLETHITEVENT_H
#define TALLERZ_BULLETHITEVENT_H

#include <client/model/Events/Event.h>
#include "common/IDs/BulletID.h"

class BulletHitEvent : public Event{
 private:
  BulletID id;
  Position pos;
  WeaponType weapon;

 public:
  BulletHitEvent(const BulletID &id, const WeaponType &type);
  virtual void process();
};

#endif //TALLERZ_BULLETHITEVENT_H
