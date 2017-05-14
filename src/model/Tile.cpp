#include "Tile.h"

Tile::Tile(Position position, TerrainType terrainType)
    : position(position), terrainType(terrainType) {}

Tile::Tile(Position &position, ObjectMap *objectMap)
    : position(position), objectMap(objectMap) {
    terrainType = LAND;
}

Position Tile::getPosition() const {
  return this->position;
}

bool Tile::operator==(const Tile &other) const {
  return this->position == other.position;
}

TerrainType Tile::getTerrainType() const {
  return this->terrainType;
}

std::string Tile::getType() const {
    return this->objectMap->getType();
}

bool Tile::isEmpty() const {
  return empty;
}

void Tile::clear() {
  this->empty = false;
}

void Tile::fill() {
  this->empty = true;
}
