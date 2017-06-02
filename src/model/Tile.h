#ifndef TALLERZ_TILE_H
#define TALLERZ_TILE_H

#include <map>
#include "Position.h"
#include "TerrainType.h"
#include "UnitID.h"
#include "UnitState.h"
#include "TerrainData.h"
#include <vector>

#define TILEWIDHT 100
#define TILEHEIGHT 100

class Tile {
 private:
  Position centerPosition;
  TerrainData terrainData;
  bool passable;
 public:
  Tile(Position tileCenterPosition, TerrainData terrainData);
  TerrainData getTerrainData() const;
  ~Tile();
  bool isPassable() const;
  void makeNotPassable();
  void makePassable();
  Position getCenterPosition() const;
  Position getCornerPosition() const;
  TerrainType getTerrainType() const;
  bool operator==(const Tile &other) const;
};

#endif //TALLERZ_TILE_H
