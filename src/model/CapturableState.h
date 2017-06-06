#ifndef TALLERZ_CAPTURABLESTATE_H
#define TALLERZ_CAPTURABLESTATE_H

#include "PlayerID.h"
struct CapturableState {
  PlayerID ownerID;
  Position pos;
  CapturableState(const PlayerID &id, const Position pos)
      : ownerID(id), pos(pos) {};
};

#endif //TALLERZ_CAPTURABLESTATE_H
