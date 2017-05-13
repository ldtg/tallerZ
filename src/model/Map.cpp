#include "Map.h"
std::vector<Tile> Map::getNeighbors(const Tile &tile) const {
  std::vector<Tile> neighborsTiles;
  std::vector<Position> neighborsPos = tile.getPosition().getNeighbors();
  for(Position& pos : neighborsPos){
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
/*void Map::move(Unit *unit) {
  map.at(unit->getCurrentPosition()).remove(unit->getId());
  map.at(unit->nextPosition()).add(unit->getId());
}
void Map::remove(Unit *unit) {
  map.at(unit->getCurrentPosition()).remove(unit->getId());
}*/
