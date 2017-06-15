#ifndef TALLERZ_NODE_H
#define TALLERZ_NODE_H

#include <vector>
#include <queue>
#include "common/Map/Position.h"
#include "common/Map/Tile.h"

class Node {
 private:
  const Tile tile;
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
  const Tile &getTile() const;
  bool operator==(const Node &node) const;
  float getTotalCost() const;
  bool isBetter(const Node &node) const;
  bool hasTile(const Tile &tile) const;
};

#endif //TALLERZ_NODE_H