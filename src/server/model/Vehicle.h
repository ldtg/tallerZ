#ifndef TALLERZ_VEHICLE_H
#define TALLERZ_VEHICLE_H

#include "Unit.h"

class Vehicle : public Unit {
 protected:
  UnitType conductor;
  virtual unsigned short getMovementSpeed(float terrainFactor) const override;
 public:
  Vehicle(const Position &current, const UnitData &data,
          const UnitType &conductorType, Player &player, Team &team);
  void changeOwner(Player *player, const Team &team, UnitType conductor);
  virtual bool canGoThrough(const TerrainData &terrainData) const override;
  virtual UnitState getUnitState() const override;
  ~Vehicle();
};

#endif //TALLERZ_VEHICLE_H
