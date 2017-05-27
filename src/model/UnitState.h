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
  PlayerID owner;
  unsigned short health;
  Weapon weapon;
  Position position;
  UnitState(const PlayerID &owner,
            unsigned short health,
            const Weapon &weapon,
            const Position &current)
      : owner(owner), health(health), weapon(weapon), position(current) {}
};

#endif //TALLERZ_UNITSTATE_H
