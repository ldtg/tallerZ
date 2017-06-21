#ifndef TALLERZ_DATAENDGAMEEVENT_H
#define TALLERZ_DATAENDGAMEEVENT_H

#include <common/IDs/TeamID.h>
struct DataEndGameEvent {
  TeamID winner;
  DataEndGameEvent(const TeamID &winner);
  DataEndGameEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(winner);
  }
};

#endif //TALLERZ_DATAENDGAMEEVENT_H
