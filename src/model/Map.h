#ifndef TALLERZ_MAP_H
#define TALLERZ_MAP_H

#include "Position.h"
#include "Tile.h"
#include <vector>
#include <map>
class Map {
 private:
  std::map<Position, Tile> map;
 public:
  std::vector<Tile> getNeighbors(const Tile &tile) const;
  Tile getTile(const Position& position) const;
};

#endif //TALLERZ_MAP_H
