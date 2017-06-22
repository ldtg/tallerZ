#ifndef TALLERZ_DATABUILDDAMAGEEVENT_H
#define TALLERZ_DATABUILDDAMAGEEVENT_H

#include <common/States/BuildState.h>
#include <common/IDs/BuildID.h>
struct DataBuildUpdateEvent {
  BuildID id;
  BuildState newState;
  DataBuildUpdateEvent(const BuildID &id, const BuildState &newState);
  DataBuildUpdateEvent() {};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, newState);
  }
};

#endif //TALLERZ_DATABUILDDAMAGEEVENT_H
