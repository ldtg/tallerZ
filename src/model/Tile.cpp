#include "Tile.h"
Tile::Tile(Position position, TerrainType terrainType)
    : position(position), terrainType(terrainType), empty(true) {}

Position Tile::getPosition() const {
  return this->position;
}
bool Tile::operator==(const Tile &other) const {
  return this->position == other.position
      && this->terrainType == other.terrainType;
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
void Tile::add(const UnitID &unitID, const UnitState &unitState) {
  units.emplace(unitID, unitState);
}
void Tile::remove(const UnitID &unitID) {
  units.erase(unitID);
}
Tile::Tile() :position(0,0), terrainType(TerrainType::LAND){}
