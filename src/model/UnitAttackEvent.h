#ifndef TALLERZ_ATTACKEVENT_H
#define TALLERZ_ATTACKEVENT_H

#include "UnitID.h"
#include "Weapon.h"
struct UnitAttackEvent {
  UnitID attacker;
  UnitID attacked;
  Weapon weapon;
};

#endif //TALLERZ_ATTACKEVENT_H
