#ifndef TALLERZ_NODE_H
#define TALLERZ_NODE_H

#include <vector>
#include <queue>
#include "Position.h"
#include "Movement.h"
class Node {
 private:
  const Position &position;
  unsigned long distance;
  unsigned long heuristic;
  unsigned long totalCost;
  Node *parent;
 public:
  Node(const Position &pos, unsigned long heuristic);
  Node(const Position &pos,
       Node *parent,
       unsigned long heuristic);

  const Position &getPosition() const;
  std::vector<Movement> makePath();
  bool operator==(const Node &node) const;
  unsigned long getTotalCost() const;
  bool isBetter(const Node &node) const;
  bool hasPosition(const Position &position) const;
};

#endif //TALLERZ_NODE_H
