#ifndef TALLERZ_BULLETSTATE_H
#define TALLERZ_BULLETSTATE_H

#include <common/Map/Position.h>
#include <common/Types/WeaponType.h>

struct BulletState {
 public:
  const WeaponType weapon;
  const Position position;
  BulletState(const WeaponType &weapon, const Position &pos);
  template<class Archive>
  void serialize(Archive &archive){
    archive(weapon,position);
  }
};

#endif //TALLERZ_BULLETSTATE_H
