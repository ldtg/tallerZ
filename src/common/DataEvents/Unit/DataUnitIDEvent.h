#ifndef TALLERZ_DATAUNITDEATHEVENT_H
#define TALLERZ_DATAUNITDEATHEVENT_H

#include <common/IDs/UnitID.h>
struct DataUnitIDEvent {
  UnitID id;
  DataUnitIDEvent(const UnitID &id): id(id){};
  DataUnitIDEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id);
  }
};

#endif //TALLERZ_DATAUNITDEATHEVENT_H
