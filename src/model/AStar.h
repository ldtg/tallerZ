#ifndef TALLERZ_ASTAR_H
#define TALLERZ_ASTAR_H

#include <queue>
#include <map>
#include "Position.h"
#include "Map.h"
#include "Movement.h"
#include "Node.h"
class AStar {
 private:
  const Map &map;
  std::map<unsigned long, Node*> open;
  std::vector<Node*> close;
  std::vector<Node*> createdNodes;
  const Position &ipos;
  const Position &epos;
  std::queue<Movement> makeQueue(std::vector<Movement> pathVector);
  std::vector<Node*> getNeighbors(Node *current);
  bool existBetter(Node *pNode) const;
  unsigned long heuristic(const Position &position, const Position &epos) const;
 public:
  AStar(const Map &map, const Position &ipos, const Position &epos);
  std::queue<Movement> find();

  ~AStar();
};

#endif //TALLERZ_ASTAR_H
