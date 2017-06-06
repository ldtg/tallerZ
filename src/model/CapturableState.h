#ifndef TALLERZ_CAPTURABLESTATE_H
#define TALLERZ_CAPTURABLESTATE_H

#include "PlayerID.h"
#include "GaiaPlayer.h"
struct CapturableState {
  PlayerID ownerID;

  CapturableState():ownerID(GaiaPlayer().getID()){}

  CapturableState(const PlayerID &id):ownerID(id){};
};

#endif //TALLERZ_CAPTURABLESTATE_H
