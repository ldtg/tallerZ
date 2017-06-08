#ifndef TALLERZ_SERVERUNITMOVEEVENT_H
#define TALLERZ_SERVERUNITMOVEEVENT_H
#include <common/Map/Position.h>
#include <common/IDs/UnitID.h>
#include <sstream>
class dataUnitMoveEvent{
 public:
  UnitID id;
  Position posTo;
 public:
  dataUnitMoveEvent(const UnitID &id, const Position &pos);
  dataUnitMoveEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, posTo); // serialize things by passing them to the archive
  }
};

#endif //TALLERZ_SERVERUNITMOVEEVENT_H
