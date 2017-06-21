#ifndef TALLERZ_DATABULLETNEWEVENT_H
#define TALLERZ_DATABULLETNEWEVENT_H

#include <common/Map/Position.h>
#include <common/Types/WeaponType.h>
#include <common/IDs/BulletID.h>
struct DataBulletNewEvent {
  BulletID id;
  WeaponType weapon;
  Position from;
  Position to;
  DataBulletNewEvent(const BulletID &id,
                     WeaponType weapon,
                     const Position &from,
                     const Position &to);
  DataBulletNewEvent() {};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, weapon, from, to);
  }
};

#endif //TALLERZ_DATABULLETNEWEVENT_H
