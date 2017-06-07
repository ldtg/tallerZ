#ifndef TALLERZ_UNITMOVEEVENT_H
#define TALLERZ_UNITMOVEEVENT_H
#include <server/model/Position.h>
#include <common/IDs/UnitID.h>
struct UnitMoveEvent {
  UnitID id;
  Position posTo;
  UnitMoveEvent(const UnitID &id, const Position &pos) : id(id), posTo(pos) {};
  UnitMoveEvent():id(R_GRUNT), posTo(0,0){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, posTo); // serialize things by passing them to the archive
  }
};

#endif //TALLERZ_UNITMOVEEVENT_H
