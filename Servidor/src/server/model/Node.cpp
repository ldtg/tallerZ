#include "Node.h"

Node::Node(const Tile &tile,
           float heuristic)
    : tile(tile),
      distance(0),
      heuristic(heuristic),
      totalCost(heuristic),
      parent(nullptr) {
}

Node::Node(const Tile &tile, Node *parent,
           float heuristic)
    : tile(tile),
      distance(parent->distance + 1
          / tile.getTerrainData().terrainFactor), //1/factor para priorizar el mas bajo
      heuristic(heuristic),
      totalCost(distance + heuristic),
      parent(parent) {
}

std::vector<Position> Node::makePath() const {
  std::vector<Position> path;
  if (parent != nullptr) {
    std::vector<Position> parentPath = parent->makePath();
    path.insert(path.begin(), parentPath.begin(), parentPath.end());
    path.push_back(this->tile.getCenterPosition());
  }
  return path;
}

bool Node::isBetter(const Node &node) const {
  return this->totalCost < node.totalCost;
}

bool Node::hasTile(const Tile &tile) const {
  return this->tile == tile;
}

Tile Node::getTile() const {
  return this->tile;
}

float Node::getTotalCost() const {
  return this->totalCost;
}

bool Node::operator==(const Node &node) const {
  return this->tile == node.tile;
}
