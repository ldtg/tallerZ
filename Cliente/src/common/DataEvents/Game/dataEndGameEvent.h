#ifndef TALLERZ_DATAENDGAMEEVENT_H
#define TALLERZ_DATAENDGAMEEVENT_H

#include <common/IDs/TeamID.h>
struct dataEndGameEvent {
  TeamID winner;
  dataEndGameEvent(const TeamID &winner);
  dataEndGameEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(winner);
  }
};

#endif //TALLERZ_DATAENDGAMEEVENT_H
