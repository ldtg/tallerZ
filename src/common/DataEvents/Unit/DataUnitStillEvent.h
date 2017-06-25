#ifndef TALLERZ_SERVIDOR_DATAUNITSTILLEVENT_H
#define TALLERZ_SERVIDOR_DATAUNITSTILLEVENT_H

#include <common/Map/Position.h>
#include <common/IDs/UnitID.h>
class DataUnitStillEvent {
 public:
  UnitID id;
  Position posTo;
 public:
  DataUnitStillEvent(const UnitID &id, const Position &pos);
  DataUnitStillEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, posTo);
  }
};

#endif //TALLERZ_SERVIDOR_DATAUNITSTILLEVENT_H
