#ifndef TALLERZ_DATAGPLAYERDEFEATEVENT_H
#define TALLERZ_DATAGPLAYERDEFEATEVENT_H

#include <common/IDs/PlayerID.h>
struct dataPlayerDefeatEvent {
  PlayerID playerID;
  dataPlayerDefeatEvent(const PlayerID &playerID);
  dataPlayerDefeatEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(playerID);
  }
};

#endif //TALLERZ_DATAGPLAYERDEFEATEVENT_H
