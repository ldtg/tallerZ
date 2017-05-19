#include "Map.h"
#include "MapBuilder.h"

Map::Map() {}

Map::Map(const std::map<Position, Tile> &map,
         unsigned short width,
         unsigned short height)
    : map(map), width(width), height(height) {}

Map::~Map() {}

std::vector<Tile> Map::getNeighbors(const Tile &tile) const {
  Position tilePosition = tile.getCenterPosition();
  tilePosition.mod(TILEWIDHT, TILEHEIGHT);
  std::vector<Tile> neighborsTiles;
  std::vector<Position> neighborsPos = tilePosition.getNeighbors();
  for (Position &pos : neighborsPos) {
    if (pos.isIn(width, height))
      neighborsTiles.push_back(map.at(pos));
  }
  return neighborsTiles;
}

Tile Map::getTile(const Position &position) const {
  Position pos = position;
  pos.mod(TILEWIDHT, TILEHEIGHT);
  return map.at(pos);
}

bool Map::canPass(const Position &positionFrom,
                    const Position &positionTo) const {
  Position actual = positionFrom;
  while (actual != positionTo) {
    actual.move(positionTo);
    if (!this->getTile(actual).isPassable())
      return false;
  }
  return true;
}

int Map::getWidht() const {
  return width;
}

int Map::getHeight() const {
  return height;
}
const std::map<UnitID, UnitState> &Map::getUnits() const {
  return units;
}
void Map::setUnits(const std::map<UnitID, UnitState> &units) {
  Map::units = units;
}
void Map::addUnit(const UnitID &unitID, const UnitState &unitState) {
  units.emplace(unitID, unitState);
}
void Map::removeUnit(const UnitID &unitID) {
  units.erase(unitID);
}
UnitState Map::getUnitState(const UnitID &unitID) const {
  return units.at(unitID);
}
UnitID Map::getUnitIDFromPosition(const Position &pos) const {
  for (auto &par : units) {
    if(pos.equalDelta(par.second.currentPosition, DELTASEARCH))
      return par.first;
  }
}

