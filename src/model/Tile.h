#ifndef TALLERZ_TILE_H
#define TALLERZ_TILE_H
#include <map>
#include "Position.h"
#include "TerrainType.h"
#include "UnitID.h"
#include "UnitState.h"

class Tile {
 private:
  Position position;
  TerrainType terrainType;
  std::map<UnitID, UnitState> units;
  //agregar build
  bool empty;
 public:
  Tile();
  Tile(Position position, TerrainType terrainType);
  void add(const UnitID &unitID, const UnitState &unitState);
  void remove(const UnitID &unitID);
  bool isEmpty() const;
  Position getPosition() const;
  void clear();
  void fill();
  TerrainType getTerrainType() const;
  bool operator==(const Tile &other) const;
};

#endif //TALLERZ_TILE_H
