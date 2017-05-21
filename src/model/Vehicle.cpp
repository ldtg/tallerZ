#include "Vehicle.h"
#include <cmath>
#include "Data.h"
Vehicle::Vehicle(const Position &current, const UnitData &data,
                 const UnitType &conductorType) : Unit(current, data, conductorType) {
}
bool Vehicle::canGoThrough(const TerrainData &terrainData) const {
  return terrainData != data.lava && terrainData != data.water;
}
unsigned short Vehicle::getMovementSpeed(float terrainFactor) const {
  float relativeDmg = 1 - (float) this->health
      / (float) data.getData(this->id.getUnitType()).health;
  return std::max((unsigned short) std::truncl(
      this->baseSpeed * terrainFactor * relativeDmg),
                  (unsigned short)
                      1);
}
Vehicle::~Vehicle() {}
