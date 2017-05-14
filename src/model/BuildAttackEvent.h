#ifndef TALLERZ_BUILDATTACKEVENT_H
#define TALLERZ_BUILDATTACKEVENT_H

#include "BuildID.h"
#include "UnitID.h"
#include "Weapon.h"
struct BuildAttackEvent {
  UnitID attacker;
  BuildID attacked;
  Weapon weapon;
};

#endif //TALLERZ_BUILDATTACKEVENT_H
