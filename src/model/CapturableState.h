#ifndef TALLERZ_CAPTURABLESTATE_H
#define TALLERZ_CAPTURABLESTATE_H

#include "PlayerID.h"
struct CapturableState {
  PlayerID ownerID;
  CapturableState(const PlayerID &id):ownerID(id){};
};

#endif //TALLERZ_CAPTURABLESTATE_H
