#ifndef TALLERZ_MAP_H
#define TALLERZ_MAP_H

#include "Position.h"
#include "Tile.h"
#include "Weapon.h"
#include "Unit.h"
#include <vector>
#include <map>
#include <string>

class Map {
 private:
  //guarda los nros de tiles ej: tile 0,0 va de 0<x<100.
  std::map<Position, Tile> map;
  //el mapa ahora tiene las unidades con el estado para poder dibujarlas.
  std::map<UnitID, UnitState> units;
  int width;
  int height;

 public:
  Map();
  Map(const std::map<Position, Tile> &map,
      unsigned short width,
      unsigned short height);
  ~Map();
  std::vector<Tile> getNeighbors(const Tile &tile) const;
  void addUnit(const UnitID &unitID, const UnitState &unitState);
  void removeUnit(const UnitID &unitID);
  Tile getTile(const Position &position) const;
  // para saber si se puede mover o atacar desde esa posicion
  // hasta la otra (no hay nada en el medio onda estructuras o algo)
  bool canPass(const Position &positionFrom,
               const Position &positionTo) const;
  //Metodos para dibujar mapa
  const std::map<Position, Tile> getMap() const;
  const std::map<UnitID, UnitState> &getUnits() const;
  UnitID getUnitIDFromPosition(const Position &pos, unsigned short range) const;
  UnitState getUnitState(const UnitID &unitID) const;
  //Para crear el mapa
  void setUnits(const std::map<UnitID, UnitState> &units);
  int getWidht() const;
  int getHeight() const;

};

#endif //TALLERZ_MAP_H
