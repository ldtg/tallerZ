#ifndef TALLERZ_DATAUNITDEATHEVENT_H
#define TALLERZ_DATAUNITDEATHEVENT_H

#include <common/IDs/UnitID.h>
struct dataUnitIDEvent {
  UnitID id;
  dataUnitIDEvent(const UnitID &id): id(id){};
  dataUnitIDEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id);
  }
};

#endif //TALLERZ_DATAUNITDEATHEVENT_H
