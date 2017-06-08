#ifndef TALLERZ_SERVERUNITMOVEEVENT_H
#define TALLERZ_SERVERUNITMOVEEVENT_H
#include <common/Map/Position.h>
#include <common/IDs/UnitID.h>
#include <sstream>
struct dataUnitMoveEvent{
 public:
  UnitID id;
  Position posTo;
 public:
  dataUnitMoveEvent(const UnitID &id, const Position &pos);
  dataUnitMoveEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, posTo);
  }
};

#endif //TALLERZ_SERVERUNITMOVEEVENT_H
