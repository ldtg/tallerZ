#ifndef TALLERZ_ASTAR_H
#define TALLERZ_ASTAR_H

#include <queue>
#include <map>
#include "common/Map/Position.h"
#include "common/Map/Map.h"
#include "Node.h"
#include "Unit.h"
#include "common/Map/Tile.h"
class AStar {
 private:
  const Map &map;
  const Unit* unit;
  std::multimap<float, Node*> open;
  std::vector<Node*> close;
  std::vector<Node*> createdNodes;
  const Tile itile;
  const Tile etile;
  const Position target;
  bool existBetter(Node *pNode) const;
  bool isInClose(Node *neighbor);
  std::vector<Node*> getNeighbors(Node *current);
  float heuristic(const Tile &itile, const Tile &etile) const;
 public:
  AStar(const Map &map, const Unit *unit,const Position &target);
  std::vector<Position> find();
  ~AStar();
};

#endif //TALLERZ_ASTAR_H
