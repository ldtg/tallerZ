#ifndef TALLERZ_MAP_H
#define TALLERZ_MAP_H

#include "Position.h"
#include "Tile.h"
#include "Weapon.h"
#include "Unit.h"
#include "MovementEvent.h"
#include "UnitAttackEvent.h"
#include <vector>
#include <map>
#include <string>

class Map {
 private:
  std::map<Position, Tile> map;
  int width;
  int height;
 public:
  Map();
  Map(std::map<Position, Tile> map, unsigned short width, unsigned short height);
  std::vector<Tile> getNeighbors(const Tile &tile) const;
  Tile getTile(const Position& position) const;
  bool canAttack(const Position &positionFrom, const Position &positionTo);
    std::vector<std::string> getTypePos(int x, int y) const;
  int getWidht() const;
  int getHeight() const;
    //procesar evento para mantener mapa actualizado
  /*void process(const MovementEvent &event);
  void process(const UnitAttackEvent &event);
  */
  /*void move(Unit *unit);
  void remove(Unit *unit);*/
};

#endif //TALLERZ_MAP_H
