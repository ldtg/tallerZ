#include <cmath>
#include "Robot.h"
Robot::Robot(Position current, UnitData data) : Unit(current,
                                                     data) {}
bool Robot::canGoThrough(TerrainData terrainData) const {
  return terrainData.type != TerrainType::LAVA;
}

unsigned short Robot::getMovementSpeed(float terrainFactor) const {
  return std::max((unsigned short) std::round(this->baseSpeed * terrainFactor),
                  (unsigned short)
                      1);
}
Robot::~Robot() {
}
