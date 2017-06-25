#ifndef TALLERZ_DATABULLETMOVEEVENT_H
#define TALLERZ_DATABULLETMOVEEVENT_H

#include <common/Map/Position.h>
#include <common/IDs/BulletID.h>
struct DataBulletMoveEvent {
  BulletID id;
  Position posTo;
  DataBulletMoveEvent(const BulletID &id, const Position &posTo);
  DataBulletMoveEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id,posTo);
  }
};

#endif //TALLERZ_DATABULLETMOVEEVENT_H
