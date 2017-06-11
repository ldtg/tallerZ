#ifndef TALLERZ_BULLET_H
#define TALLERZ_BULLET_H

#include "common/Map/Position.h"
#include "Attackable.h"
#include "common/IDs/BulletID.h"
#include "common/States/BulletState.h"
class Bullet {
 private:
  BulletID id;
  Weapon weapon;
  Attackable *target;
  Position currentPosition;
 public:
  Bullet(const Weapon &weapon, const Position &current,
         Attackable *target);
  bool didHit() const;
  BulletID getId() const;
  Weapon getWeapon() const;
  Position getFrom() const;
  Position getTo() const;
  BulletState getState() const;
  void doHit();
  void move();
};

#endif //TALLERZ_BULLET_H