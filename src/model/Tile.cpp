#include <iostream>
#include "Tile.h"

Tile::Tile(Position position, TerrainType terrainType)
    : position(position), terrainType(terrainType), empty(true) {}

/*
Tile::Tile(Position &position, ObjectMap *background, ObjectMap *objectMap)
    : position(position), background(background), objectMap(objectMap) {
    terrainType = LAND;
}

Tile::Tile(const Tile &other) {
    this->position = std::move(other.position);
    this->background = other.background;
    this->objectMap = other.objectMap;
    this->units = other.units;
    this->empty = other.empty;
}

Tile& Tile::operator=(const Tile &other) {
    this->position = std::move(other.position);
    this->background = other.background;
    this->objectMap = other.objectMap;
    this->units = other.units;
    this->empty = other.empty;

    return *this;
}

Tile::Tile(Tile &&other) {
    this->position = std::move(other.position);
    this->background = other.background;
    this->objectMap = other.objectMap;
    this->units = other.units;
    this->empty = other.empty;

    other.background = NULL;
    other.objectMap = NULL;
}
*/

Tile::~Tile() {
/*
    if (background != NULL)
        delete background;
    if (objectMap != NULL)
        delete objectMap;
*/
}

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
/*
std::vector<std::string> Tile::getType() const {
    std::vector<std::string> type(2);
    // Todos los Tile deben tener un fondo.
    type[0] = this->background->getType();

    if (this->objectMap == NULL)
        type[1] = "";
    else
        type[1] = this->objectMap->getType();

    return std::move(type);
}
*/

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
