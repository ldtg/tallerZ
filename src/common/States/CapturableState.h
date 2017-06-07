#ifndef TALLERZ_CAPTURABLESTATE_H
#define TALLERZ_CAPTURABLESTATE_H

#include "common/IDs/PlayerID.h"
#include "GaiaPlayer.h"
struct CapturableState {
  PlayerID ownerID;
  Position pos;

  CapturableState():ownerID(GaiaPlayer().getID()){}
  CapturableState(const PlayerID &id, const Position pos)
      : ownerID(id), pos(pos) {};
};

#endif //TALLERZ_CAPTURABLESTATE_H
