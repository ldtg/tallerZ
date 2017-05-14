#ifndef TALLERZ_TILE_H
#define TALLERZ_TILE_H

#include <map>
#include "Position.h"
#include "TerrainType.h"
#include "UnitID.h"
#include "UnitState.h"
#include "ObjectMap.h"

class Tile {
 private:
  const Position position;
//  const TerrainType terrainType;
  TerrainType terrainType;
  const ObjectMap *objectMap;
  std::map<UnitID, UnitState> units;
  //agregar build
  bool empty;
 public:
  Tile();
  Tile(Position position, TerrainType terrainType);
  Tile(Position &position, ObjectMap *objectMap);
  void add(const UnitID &unitID, const UnitState &unitState);
  void remove(const UnitID &unitID);
  bool isEmpty() const;
  Position getPosition() const;
  void clear();
  void fill();
  TerrainType getTerrainType() const;
  std::string getType() const;
  bool operator==(const Tile &other) const;
};

#endif //TALLERZ_TILE_H
