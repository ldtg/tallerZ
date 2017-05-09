#ifndef TALLERZ_UNIT_H
#define TALLERZ_UNIT_H
#include <queue>
#include "Position.h"
#include "TerrainType.h"
class Unit {
 private:
  Position& currentPosition;
  std::queue<Movement> movements;
 public:
  virtual Position getcurrentPosition() const;
  virtual void setMovements(std::queue<Movement> moves);
  virtual Position move();
  virtual bool canGoThrough(TerrainType terrainType) const = 0;
  virtual float getMovementCost(TerrainType terrainType) const = 0;
};

#endif //TALLERZ_UNIT_H
