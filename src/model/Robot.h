#ifndef TALLERZ_ROBOT_H
#define TALLERZ_ROBOT_H

#include "Unit.h"
class Robot : public Unit {
 public:
  Robot(Position current, UnitData data);
  virtual bool canGoThrough(TerrainData terrainData) const override;
  virtual unsigned short getMovementSpeed(float terrainFactor) const override;
  ~Robot();
};

#endif //TALLERZ_ROBOT_H
