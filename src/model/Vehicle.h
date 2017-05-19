#ifndef TALLERZ_VEHICLE_H
#define TALLERZ_VEHICLE_H

#include "Unit.h"
class Vehicle : public Unit{
 public:
  Vehicle(const Position &current, const UnitData &data);
  virtual bool canGoThrough(const TerrainData &terrainData) const override;
  virtual unsigned short getMovementSpeed(float terrainFactor) const override;
  ~Vehicle();
};

#endif //TALLERZ_VEHICLE_H