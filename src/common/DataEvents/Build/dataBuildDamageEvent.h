#ifndef TALLERZ_DATABUILDDAMAGEEVENT_H
#define TALLERZ_DATABUILDDAMAGEEVENT_H

#include <common/States/BuildState.h>
#include <common/IDs/BuildID.h>
struct dataBuildDamageEvent {
  BuildID id;
  BuildState newState;
  dataBuildDamageEvent(const BuildID &id, const BuildState &newState);
  dataBuildDamageEvent() {};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, newState);
  }
};

#endif //TALLERZ_DATABUILDDAMAGEEVENT_H
