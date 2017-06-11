#ifndef TALLERZ_DATABUILDDESTROYEDEVENT_H
#define TALLERZ_DATABUILDDESTROYEDEVENT_H

#include <common/IDs/BuildID.h>
struct dataBuildIDEvent {
  BuildID id;
  dataBuildIDEvent(const BuildID &id);
  dataBuildIDEvent() {};
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id);
  }
};

#endif //TALLERZ_DATABUILDDESTROYEDEVENT_H
