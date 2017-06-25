#ifndef TALLERZ_ROBOT_H
#define TALLERZ_ROBOT_H

#include "Unit.h"
class Robot : public Unit {
 protected:
  virtual unsigned short getMovementSpeed(float terrainFactor) const override;
 public:
  Robot(const Position &current, const UnitData &data, Player &player, Team &team);
  virtual bool canGoThrough(const TerrainData &terrainData) const override;
  virtual UnitState getUnitState() const override;
  virtual ~Robot();
};

#endif //TALLERZ_ROBOT_H
