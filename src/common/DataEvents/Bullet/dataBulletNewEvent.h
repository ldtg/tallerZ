#ifndef TALLERZ_DATABULLETNEWEVENT_H
#define TALLERZ_DATABULLETNEWEVENT_H

#include <common/Map/Position.h>
#include <common/Types/WeaponType.h>
#include <common/IDs/BulletID.h>
struct dataBulletNewEvent {
  BulletID id;
  WeaponType weapon;
  Position from;
  Position to;
  dataBulletNewEvent(const BulletID &id,
                     WeaponType weapon,
                     const Position &from,
                     const Position &to);
  dataBulletNewEvent() {};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, weapon, from, to);
  }
};

#endif //TALLERZ_DATABULLETNEWEVENT_H
