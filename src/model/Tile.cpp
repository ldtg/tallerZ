#include <iostream>
#include "Tile.h"

Tile::Tile(Position centerPosition,
            TerrainData terrainData)
    : centerPosition(centerPosition),
      terrainData(terrainData),
      passable(true){}

Tile::~Tile() {
}

Position Tile::getCenterPosition() const {
  return this->centerPosition;
}

bool Tile::operator==(const Tile &other) const {
  return this->centerPosition == other.centerPosition
      && this->terrainData == other.terrainData;
}

TerrainData Tile::getTerrainData() const {
  return this->terrainData;
}

bool Tile::isPassable()const {
  return passable;
}

void Tile::add(const UnitID &unitID, const UnitState &unitState) {
  units.emplace(unitID, unitState);
}
void Tile::remove(const UnitID &unitID) {
  units.erase(unitID);
}
