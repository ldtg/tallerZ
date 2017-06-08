#ifndef TALLERZ_UNITSTATE_H
#define TALLERZ_UNITSTATE_H

#include <common/IDs/PlayerID.h>
#include <server/model/Weapon.h>
#include <common/Map/Position.h>
#include <common/Types/UnitType.h>

#define UNITWIDHT 16
#define UNITHEIGHT 16

struct UnitState {
 public:
  PlayerID owner;
  unsigned short health;
  WeaponType weapon;
  Position position;
  UnitType secondType;

  UnitState(UnitType secondType, const PlayerID &owner,
            unsigned short health,
            const WeaponType &weapon,
            const Position &current)
      : secondType(secondType),
        owner(owner),
        health(health),
        weapon(weapon),
        position(current) {}
  template<class Archive>
  void serialize(Archive &archive) {
    archive(owner, health, weapon, position, secondType);
  }
};

#endif //TALLERZ_UNITSTATE_H
