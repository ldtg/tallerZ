#include <iostream>
#include "Tile.h"

Tile::Tile(Position position, TerrainType terrainType)
    : position(position), terrainType(terrainType), empty(true) {}

Tile::Tile(Position &position, ObjectMap *background, ObjectMap *objectMap)
    : position(position), background(background), objectMap(objectMap) {
    terrainType = LAND;
}

Tile::~Tile() {
//    delete background;
//    delete objectMap;
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

std::vector<std::string> Tile::getType() const {
    std::vector<std::string> type(2);

//    std::cout << "A" << std::endl;
//    bool n = this->background == NULL;
//    std::cout << n << std::endl;
//    std::cout << "type: " << this->background->getType() << std::endl;

    // Todos los Tile deben tener un fondo.
    type[0] = this->background->getType();

//    std::cout << "B" << std::endl;
    if (this->objectMap == NULL)
        type[1] = "";
    else
        type[1] = this->objectMap->getType();
//    std::cout << "D" << std::endl;

    return std::move(type);
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

//Tile::Tile() :position(0,0), terrainType(TerrainType::LAND){}
