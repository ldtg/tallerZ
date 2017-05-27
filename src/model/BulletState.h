#ifndef TALLERZ_BULLETSTATE_H
#define TALLERZ_BULLETSTATE_H

#include "Position.h"
#include "Weapon.h"
struct BulletState {
 public:
  const Weapon weapon;
  const Position position;
  BulletState(const Weapon &weapon, const Position &pos);
};

#endif //TALLERZ_BULLETSTATE_H