#include "Robot.h"
Robot::Robot(Position current, UnitType type) : Unit(current,
                                                     type,
                                                     WeaponType::BULLET) {}
bool Robot::canGoThrough(TerrainType terrainType) const {
  return terrainType != TerrainType::LAVA;
}
float Robot::getMovementCost(TerrainType terrainType) const {
  return 10;
}
Robot::~Robot() {
}
