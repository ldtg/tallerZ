#include "Vehicle.h"
#include <cmath>
#include "Data.h"
Vehicle::Vehicle(const Position &current, const UnitData &data) : Unit(current,
                                                                       data) {
}
bool Vehicle::canGoThrough(const TerrainData &terrainData) const {
  return terrainData != data.lava && terrainData != data.water ;
}
unsigned short Vehicle::getMovementSpeed(float terrainFactor) const {
  //TODO: seguir data tiene max health
  //float relativeDmg = this->health / ; Seguir
  return std::max((unsigned short) std::truncl(this->baseSpeed * terrainFactor),
                  (unsigned short)
                      1);
}
Vehicle::~Vehicle() {}
