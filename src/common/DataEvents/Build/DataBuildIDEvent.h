#ifndef TALLERZ_DATABUILDDESTROYEDEVENT_H
#define TALLERZ_DATABUILDDESTROYEDEVENT_H

#include <common/IDs/BuildID.h>
struct DataBuildIDEvent {
  BuildID id;
  DataBuildIDEvent(const BuildID &id);
  DataBuildIDEvent() {};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id);
  }
};

#endif //TALLERZ_DATABUILDDESTROYEDEVENT_H
