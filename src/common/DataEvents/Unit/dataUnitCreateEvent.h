#ifndef TALLERZ_DATAUNITCREATEEVENT_H
#define TALLERZ_DATAUNITCREATEEVENT_H

#include <common/States/UnitState.h>
#include <common/IDs/UnitID.h>
struct dataUnitCreateEvent {
  UnitID id;
  UnitState state;
  dataUnitCreateEvent(const UnitID &id, const UnitState &state);
  dataUnitCreateEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, state);
  }
};

#endif //TALLERZ_DATAUNITCREATEEVENT_H
