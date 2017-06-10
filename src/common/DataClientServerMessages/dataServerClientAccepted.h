#ifndef TALLERZ_DATASERVERCLIENTACCEPTED_H
#define TALLERZ_DATASERVERCLIENTACCEPTED_H

#include <common/IDs/TeamID.h>
#include <common/IDs/PlayerID.h>
struct dataServerClientAccepted {
  PlayerID id;
  TeamID teamID;
  dataServerClientAccepted(const PlayerID &id, const TeamID &teamID);
  dataServerClientAccepted();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(id, teamID);
  }
};

#endif //TALLERZ_DATASERVERCLIENTACCEPTED_H
