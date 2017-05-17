#ifndef TALLERZ_UNITSTATE_H
#define TALLERZ_UNITSTATE_H

#include "MovementState.h"
#include "Attackable.h"
#include "UnitType.h"
#include "UnitData.h"
struct UnitState {
 public:
  unsigned long health;
  Weapon weapon;
  UnitState(unsigned long health, Weapon weapon)
      : health(health), weapon(weapon) {}
};

#endif //TALLERZ_UNITSTATE_H
