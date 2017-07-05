#ifndef TALLERZ_DATAGPLAYERDEFEATEVENT_H
#define TALLERZ_DATAGPLAYERDEFEATEVENT_H

#include <common/IDs/PlayerID.h>
struct DataPlayerDefeatEvent {
  PlayerID playerID;
  DataPlayerDefeatEvent(const PlayerID &playerID);
  DataPlayerDefeatEvent();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(playerID);
  }
};

#endif //TALLERZ_DATAGPLAYERDEFEATEVENT_H
