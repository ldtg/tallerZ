#ifndef TALLERZ_ASTAR_H
#define TALLERZ_ASTAR_H

#include <queue>
#include <map>
#include "Position.h"
#include "Map.h"
#include "Node.h"
#include "Unit.h"
#include "Tile.h"
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
  std::queue<Position> makeQueue(std::vector<Position> pathVector);
  std::vector<Node*> getNeighbors(Node *current);
  bool existBetter(Node *pNode) const;
  float heuristic(const Tile &itile, const Tile &etile) const;
 public:
  AStar(const Map &map, const Unit *unit,const Position &target);
  std::vector<Position> find();

  ~AStar();
  bool isInClose(Node *neighbor);
};

#endif //TALLERZ_ASTAR_H
