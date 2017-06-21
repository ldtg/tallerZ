#ifndef TALLERZ_NODE_H
#define TALLERZ_NODE_H

#include <vector>
#include <queue>
#include "common/Map/Position.h"
#include "common/Map/Tile.h"

class Node {
 private:
  Tile tile;
  float distance;
  float heuristic;
  float totalCost;
  Node *parent;
 public:
  Node(const Tile &tile, float heuristic);
  Node(const Tile &tile,
       Node *parent,
       float heuristic);
  std::vector<Position> makePath() const;
  bool isBetter(const Node &node) const;
  bool hasTile(const Tile &tile) const;
  Tile getTile() const;
  float getTotalCost() const;
  bool operator==(const Node &node) const;
};

#endif //TALLERZ_NODE_H
