#ifndef TALLERZ_BULLET_H
#define TALLERZ_BULLET_H

#include "common/Map/Position.h"
#include "Attackable.h"
#include "common/IDs/BulletID.h"
#include "common/States/BulletState.h"
//Modela una bala que se mueve hacia su objetivo
class Bullet {
 private:
  BulletID id;
  Weapon weapon;
  Attackable *target;
  Position currentPosition;
 public:
  Bullet(const Weapon &weapon, const Position &current,
         Attackable *target);
  //Avanza en un paso hacia el objetivo .
  void move();
  //Si la bala llegó a su objetivo se lo informa.
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
