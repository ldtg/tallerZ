#ifndef TALLERZ_VEHICLE_H
#define TALLERZ_VEHICLE_H

#include "Unit.h"

class Vehicle : public Unit{
 private:
  UnitType conductor;

 public:
  Vehicle(const Position &current, const UnitData &data,
          const UnitType& conductorType, Player &player, Team &team);
  ~Vehicle();

  void capture(Player &player, Team &team, UnitType conductor);
  virtual bool canGoThrough(const TerrainData &terrainData) const override;
  virtual unsigned short getMovementSpeed(float terrainFactor) const override;
  virtual UnitState getUnitState() const override;
};

#endif //TALLERZ_VEHICLE_H
