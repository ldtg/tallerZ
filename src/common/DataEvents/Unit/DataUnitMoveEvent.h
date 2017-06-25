#ifndef TALLERZ_SERVERUNITMOVEEVENT_H
#define TALLERZ_SERVERUNITMOVEEVENT_H
#include <common/Map/Position.h>
#include <common/IDs/UnitID.h>
#include <sstream>
struct DataUnitMoveEvent{
 public:
  UnitID id;
  Position posTo;
 public:
  DataUnitMoveEvent(const UnitID &id, const Position &pos);
  DataUnitMoveEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, posTo);
  }
};

#endif //TALLERZ_SERVERUNITMOVEEVENT_H
