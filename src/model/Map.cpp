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
