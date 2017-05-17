#include "Map.h"
#include "MapBuilder.h"

Map::Map() {}

Map::Map(std::map<Position, Tile> map,
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

bool Map::canAttack(const Position &positionFrom, const Position &positionTo) {
  return false;
}

int Map::getWidht() const {
  return width;
}

int Map::getHeight() const {
  return height;
}


/*void Map::move(Unit *unit) {
  map.at(unit->getCurrentPosition()).remove(unit->getId());
  map.at(unit->nextPosition()).add(unit->getId());
}
void Map::remove(Unit *unit) {
  map.at(unit->getCurrentPosition()).remove(unit->getId());
}*/
