#ifndef TALLERZ_UNITSTATE_H
#define TALLERZ_UNITSTATE_H

#include <common/IDs/PlayerID.h>
#include <server/model/Weapon.h>
#include <common/Map/Position.h>
#include <common/Types/UnitType.h>

struct UnitState {
 public:
  PlayerID owner;
  unsigned short healthPercent;
  WeaponType weapon;
  Position position;
  UnitType secondType;
  UnitState(){};
  UnitState(UnitType secondType, const PlayerID &owner,
            unsigned short health,
            const WeaponType &weapon,
            const Position &current)
      : secondType(secondType),
        owner(owner),
        healthPercent(health),
        weapon(weapon),
        position(current) {}
  template<class Archive>
  void serialize(Archive &archive) {
    archive(owner, healthPercent, weapon, position, secondType);
  }
};

#endif //TALLERZ_UNITSTATE_H
