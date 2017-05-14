#ifndef TALLERZ_MOVEMENTEVENT_H
#define TALLERZ_MOVEMENTEVENT_H

#include "UnitID.h"
#include "Position.h"
struct MovementEvent {
  UnitID unit;
  Position from;
  Position to;
};

#endif //TALLERZ_MOVEMENTEVENT_H
