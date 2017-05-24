#ifndef TALLERZ_UNITSTATE_H
#define TALLERZ_UNITSTATE_H

#include "MovementState.h"
#include "Attackable.h"
#include "UnitType.h"
#include "UnitData.h"

#define UNITWIDHT 16
#define UNITHEIGHT 16

struct UnitState {
 public:
  unsigned long health;
  Weapon weapon;
  Position currentPosition;
  UnitState(unsigned long health, Weapon weapon, Position current)
      : health(health), weapon(weapon), currentPosition(current) {}
};

#endif //TALLERZ_UNITSTATE_H
