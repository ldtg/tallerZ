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
  void move();
  void doHit();
  BulletID getId() const;
  Weapon getWeapon() const;
  Position getFrom() const;
  Position getTo() const;
  BulletState getState() const;
  bool didHit() const;
  ~Bullet();
};

#endif //TALLERZ_BULLET_H
