#ifndef TALLERZ_WEAPON_H
#define TALLERZ_WEAPON_H

#include "WeaponType.h"
struct Weapon {
  WeaponType type;
  unsigned short damage;
  bool isExplosive;
  unsigned short speed;
};

#endif //TALLERZ_WEAPON_H
