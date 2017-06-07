#ifndef TALLERZ_BULLET_H
#define TALLERZ_BULLET_H

#include "Position.h"
#include "Attackable.h"
#include "BulletID.h"
#include "BulletState.h"
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
