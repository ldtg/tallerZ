#ifndef TALLERZ_ROBOT_H
#define TALLERZ_ROBOT_H

#include "Unit.h"
class Robot : public Unit {
 public:
  Robot(const Position &current, const UnitData &data, Player &player, Team &team);
  virtual bool canGoThrough(const TerrainData &terrainData) const override;
  virtual unsigned short getMovementSpeed(float terrainFactor) const override;
  ~Robot();
};

#endif //TALLERZ_ROBOT_H
