#ifndef TALLERZ_DATABUILDDAMAGEEVENT_H
#define TALLERZ_DATABUILDDAMAGEEVENT_H

#include <common/States/BuildState.h>
#include <common/IDs/BuildID.h>
struct dataBuildUpdateEvent {
  BuildID id;
  BuildState newState;
  dataBuildUpdateEvent(const BuildID &id, const BuildState &newState);
  dataBuildUpdateEvent() {};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, newState);
  }
};

#endif //TALLERZ_DATABUILDDAMAGEEVENT_H
