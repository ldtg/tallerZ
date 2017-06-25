#include "Vehicle.h"
#include <cmath>
#include "Data.h"

Vehicle::Vehicle(const Position &current, const UnitData &data,
                 const UnitType &conductorType, Player &player, Team &team)
    : Unit(current, data, player, team), conductor(conductorType) {}

Vehicle::~Vehicle() {}

bool Vehicle::canGoThrough(const TerrainData &terrainData) const {
  return terrainData != data.lava && terrainData != data.water;
}

unsigned short Vehicle::getMovementSpeed(float terrainFactor) const {
  float relativeDmg =
      1 - ((float) (data.getData(this->id.getType()).health - this->health)
          / (float) data.getData(this->id.getType()).health);

  return std::max((unsigned short) std::truncl(
      this->baseSpeed * terrainFactor * relativeDmg),
                  (unsigned short)
                      1);
}

UnitState Vehicle::getUnitState() const {
  return UnitState(conductor,
                   owner->getID(),
                   health,
                   weapon.type,
                   currentPosition);
}

void Vehicle::changeOwner(Player *player, const Team &team, UnitType conductor) {
  this->owner = player;
  this->team = team;
  this->conductor = conductor;
}
