#ifndef TALLERZ_ROBOTFACTORY_H
#define TALLERZ_ROBOTFACTORY_H
#include "Data.h"
#include "Robot.h"
#include "Vehicle.h"
extern Data data;
class UnitFactory {
 public:
  static Robot createGrunt(const Position &pos, Player& player, Team &team);
  static Robot* createGruntDynamic(const Position &pos, Player& player, Team &team);
  static Robot createTough(const Position &pos, Player& player, Team &team);
  static Robot* createToughDynamic(const Position &pos, Player& player, Team &team);
  static Vehicle createJeep(const Position &pos, Player& player, Team &team);
  static Vehicle* createJeepDynamic(const Position &pos, Player& player, Team &team);
  static Unit* createUnitDynamic(const Position &pos, const UnitType &type, Player& player, Team &team);
  static Vehicle* createVehicleDynamic(const Position &pos, const UnitType &type, Player& player, Team &team);
};

#endif //TALLERZ_ROBOTFACTORY_H
