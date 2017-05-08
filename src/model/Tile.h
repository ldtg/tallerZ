#ifndef TALLERZ_TILE_H
#define TALLERZ_TILE_H
#include "Position.h"
#include "TerrainType.h"

class Tile {
 private:
  const Position position;
  const TerrainType terrainType;
  bool empty;
 public:
  Tile(Position position, TerrainType terrainType);
  bool isEmpty() const;
  Position getPosition() const;
  void clear();
  void fill();
  TerrainType getTerrainType() const;
  bool operator==(const Tile &other) const;
};

#endif //TALLERZ_TILE_H
