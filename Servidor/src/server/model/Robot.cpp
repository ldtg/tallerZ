#include <cmath>
#include "Robot.h"
#include "Data.h"
Robot::Robot(const Position &current,
             const UnitData &data,
             Player &player,
             Team &team) : Unit(current,
                                data, player, team) {}
bool Robot::canGoThrough(const TerrainData &terrainData) const {
  return terrainData != data.lava;
}

unsigned short Robot::getMovementSpeed(float terrainFactor) const {
  return std::max((unsigned short) std::truncl(this->baseSpeed * terrainFactor),
                  (unsigned short)
                      1);
}

UnitState Robot::getUnitState() const {
  return UnitState(this->getId().getType(),
                   owner->getID(),
                   (unsigned short) (((float)health/(float)data.getData(id.getType()).health)*100), //Pasa el porcentaje
                   weapon.type,
                   currentPosition);
}

Robot::~Robot() {}
