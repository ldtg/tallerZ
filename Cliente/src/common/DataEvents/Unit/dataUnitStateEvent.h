#ifndef TALLERZ_DATAUNITCREATEEVENT_H
#define TALLERZ_DATAUNITCREATEEVENT_H

#include <common/States/UnitState.h>
#include <common/IDs/UnitID.h>
struct dataUnitStateEvent {
  UnitID id;
  UnitState state;
  dataUnitStateEvent(const UnitID &id, const UnitState &state);
  dataUnitStateEvent(){};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, state);
  }
};

#endif //TALLERZ_DATAUNITCREATEEVENT_H
