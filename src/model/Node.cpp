#include "Node.h"
Node::Node(const Tile &tile,
           float heuristic)
    : tile(tile),
      distance(0),
      heuristic(heuristic),
      totalCost(heuristic) {
}
Node::Node(const Tile &tile, Node *parent, float distance,
           float heuristic)
    : tile(tile),
      distance(parent->distance + distance),
      heuristic(heuristic),
      totalCost(distance + heuristic),
      parent(parent) {
}
const Tile &Node::getTile() const {
  return this->tile;
}
std::vector<Movement> Node::makePath() const {
  std::vector<Movement> path;
  if (parent != nullptr) {
    std::vector<Movement> parentPath = parent->makePath();
    path.insert(path.end(), parentPath.begin(), parentPath.end());

    Movement
        move = parent->tile.getPosition().getMovement(this->tile.getPosition());
    path.push_back(move);
  }
  return path;
}

bool Node::operator==(const Node &node) const {
  return this->tile == node.tile;
}

bool Node::isBetter(const Node &node) const {
  return this->totalCost < node.totalCost;
}
float Node::getTotalCost() const {
  return this->totalCost;
}

bool Node::hasTile(const Tile &tile) const {
  return this->tile == tile;
}

