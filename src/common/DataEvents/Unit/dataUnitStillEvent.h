#ifndef TALLERZ_CLIENTE_DATAUNITSTILLEVENT_H
#define TALLERZ_CLIENTE_DATAUNITSTILLEVENT_H

#include <common/Map/Position.h>
#include <common/IDs/UnitID.h>
class dataUnitStillEvent {
 public:
  UnitID id;
  Position posTo;
 public:
  dataUnitStillEvent(const UnitID &id, const Position &pos);
  dataUnitStillEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, posTo);
  }
};


#endif //TALLERZ_CLIENTE_DATAUNITSTILLEVENT_H
