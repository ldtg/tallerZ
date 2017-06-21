#ifndef TALLERZ_DATABULLETHITEVENT_H
#define TALLERZ_DATABULLETHITEVENT_H

#include <common/Types/WeaponType.h>
#include <common/Map/Position.h>
#include <common/IDs/BulletID.h>
struct DataBulletHitEvent {
  BulletID id;
  Position pos;
  WeaponType weapon;
  DataBulletHitEvent(const BulletID &id,
                     const Position &pos,
                     WeaponType weapon);
  DataBulletHitEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, pos, weapon);
  }
};

#endif //TALLERZ_DATABULLETHITEVENT_H
