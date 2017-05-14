#ifndef TALLERZ_WEAPON_H
#define TALLERZ_WEAPON_H

#include "WeaponType.h"
class Weapon {
 private:
  WeaponType type;
  unsigned short damage;
 public:
  Weapon(WeaponType type);
  unsigned short getDamage();
};

#endif //TALLERZ_WEAPON_H
