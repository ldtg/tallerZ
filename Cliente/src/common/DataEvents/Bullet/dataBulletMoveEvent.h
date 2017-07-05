#ifndef TALLERZ_DATABULLETMOVEEVENT_H
#define TALLERZ_DATABULLETMOVEEVENT_H

#include <common/Map/Position.h>
#include <common/IDs/BulletID.h>
struct dataBulletMoveEvent {
  BulletID id;
  Position posTo;
  dataBulletMoveEvent(const BulletID &id, const Position &posTo);
  dataBulletMoveEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id,posTo);
  }
};

#endif //TALLERZ_DATABULLETMOVEEVENT_H
