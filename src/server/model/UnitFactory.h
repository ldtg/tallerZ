#ifndef TALLERZ_ROBOTFACTORY_H
#define TALLERZ_ROBOTFACTORY_H
#include "Data.h"
#include "Robot.h"
#include "Vehicle.h"
class UnitFactory {
 public:
  static Unit* createUnitDynamic(const Position &pos, const UnitType &type, Player& player, Team &team);
  static Vehicle* createVehicleDynamic(const Position &pos, const UnitType &type, Player& player, Team &team);
};

#endif //TALLERZ_ROBOTFACTORY_H
