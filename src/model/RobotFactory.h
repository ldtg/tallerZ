#ifndef TALLERZ_ROBOTFACTORY_H
#define TALLERZ_ROBOTFACTORY_H
#include "Data.h"
#include "Robot.h"
extern Data data;
class RobotFactory {
 public:
  static Robot createGrunt(const Position &pos);
};

#endif //TALLERZ_ROBOTFACTORY_H
