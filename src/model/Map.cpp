#include "Map.h"
#include "Land.h"

Map::Map() {
    Position pos(0, 0);
    ObjectMap *land = new Land("land");
    Tile tile(pos, land);

    map.insert(std::pair<Position,Tile>(pos, tile));
}

Map::Map(std::map<Position, Tile> map,
         unsigned short width,
         unsigned short height)
        : map(map), width(width), height(height) {}

std::vector<Tile> Map::getNeighbors(const Tile &tile) const {
  std::vector<Tile> neighborsTiles;
  std::vector<Position> neighborsPos = tile.getPosition().getNeighbors();
  for (Position &pos : neighborsPos) {
    if (pos.isIn(width, height))
      neighborsTiles.push_back(map.at(pos));
  }
  return neighborsTiles;
}

Tile Map::getTile(const Position &position) const {
  return map.at(position);
}

bool Map::canAttack(const Position &positionFrom, const Position &positionTo) {
  return false;
}

std::string Map::getTypePos(int x, int y) const {
    Position posAux(x, y);
    return map.at(posAux).getType();
}


/*void Map::move(Unit *unit) {
  map.at(unit->getCurrentPosition()).remove(unit->getId());
  map.at(unit->nextPosition()).add(unit->getId());
}
void Map::remove(Unit *unit) {
  map.at(unit->getCurrentPosition()).remove(unit->getId());
}*/
