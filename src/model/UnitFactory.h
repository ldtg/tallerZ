#ifndef TALLERZ_ROBOTFACTORY_H
#define TALLERZ_ROBOTFACTORY_H
#include "Data.h"
#include "Robot.h"
#include "Vehicle.h"
extern Data data;
class UnitFactory {
 public:
  static Robot createGrunt(const Position &pos);
  static Robot* createGruntDynamic(const Position &pos);
  static Vehicle createJeep(const Position &pos);
  static Vehicle* createJeepDynamic(const Position &pos);
};

#endif //TALLERZ_ROBOTFACTORY_H
