#ifndef TALLERZ_TILE_H
#define TALLERZ_TILE_H

#include <map>
#include "Position.h"
#include "TerrainType.h"
#include "UnitID.h"
#include "UnitState.h"
#include "ObjectMap.h"
#include <vector>

class Tile {
 private:
  Position position;
//  const TerrainType terrainType;
  TerrainType terrainType;
//  const ObjectMap *background;
//  const ObjectMap *objectMap;
// cambiar por vida
  std::map<UnitID, UnitState> units;
  //agregar build
  bool empty;
 public:
  Tile();
  Tile(Position position, TerrainType terrainType);
//  Tile(Position &position, ObjectMap *background, ObjectMap *objectMap);
//  Tile(const Tile &other);
//  Tile& operator=(const Tile&);
//  Tile(Tile&& other);
//  Tile& operator=(Tile&& other);
    ~Tile();
  void add(const UnitID &unitID, const UnitState &unitState);
  void remove(const UnitID &unitID);
  bool isEmpty() const;
  Position getPosition() const;
  void clear();
  void fill();
  TerrainType getTerrainType() const;
//  std::vector<std::string> getType() const;
  bool operator==(const Tile &other) const;
};

#endif //TALLERZ_TILE_H
