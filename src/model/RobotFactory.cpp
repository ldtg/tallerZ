#include "RobotFactory.h"
Robot RobotFactory::createGrunt(const Position &pos) {
  return Robot(pos, data.grunt);
}
Unit *RobotFactory::createGruntDynamic(const Position &pos) {
  return new Robot(pos, data.grunt);
}
