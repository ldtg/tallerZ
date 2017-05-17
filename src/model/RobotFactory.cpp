#include "RobotFactory.h"
Robot RobotFactory::createGrunt(const Position &pos) {
  return Robot(pos, data.grunt);
}
