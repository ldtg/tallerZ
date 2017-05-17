#ifndef TALLERZ_TILE_H
#define TALLERZ_TILE_H

#include <map>
#include "Position.h"
#include "TerrainType.h"
#include "UnitID.h"
#include "UnitState.h"
#include "ObjectMap.h"
#include "TerrainData.h"
#include <vector>
#define TILEWIDHT 100
#define TILEHEIGHT 100
class Tile {
 private:
  Position centerPosition;
  TerrainData terrainData;
 private:
  std::map<UnitID, UnitState> units;
  //agregar build
  bool passable;
 public:
  Tile(Position tileCenterPosition, TerrainData terrainData);
  TerrainData getTerrainData() const;
  ~Tile();
  void add(const UnitID &unitID, const UnitState &unitState);
  void remove(const UnitID &unitID);
  bool isPassable() const;
  Position getCenterPosition() const;
  bool operator==(const Tile &other) const;
};

#endif //TALLERZ_TILE_H
