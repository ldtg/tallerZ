#ifndef TALLERZ_ROBOT_H
#define TALLERZ_ROBOT_H

#include "Unit.h"
class Robot : public Unit {
 public:
  Robot(Position current, UnitType type);
  virtual bool canGoThrough(TerrainType terrainType) const;
  virtual float getMovementCost(TerrainType terrainType) const;
};

#endif //TALLERZ_ROBOT_H
