#include "Tile.h"
Tile::Tile(Position position, TerrainType terrainType)
    : position(position), terrainType(terrainType) {}

Position Tile::getPosition() const {
  return this->position;
}
bool Tile::operator==(const Tile &other) const {
  return this->position == other.position;
}
TerrainType Tile::getTerrainType() const {
  return this->terrainType;
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
