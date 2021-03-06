#ifndef TALLERZ_UNITDATA_H
#define TALLERZ_UNITDATA_H

#include "Weapon.h"
#include "common/Types/UnitType.h"

struct UnitData {
  UnitType type;
  Weapon weapon;
  float secsUntilFire;
  unsigned short range;
  unsigned short health;
  unsigned short speed;
  unsigned short factoryRate;
  unsigned short factoryBaseTimeInSec;
  unsigned short factoryMinimunTechLevel;
};

#endif //TALLERZ_UNITDATA_H
