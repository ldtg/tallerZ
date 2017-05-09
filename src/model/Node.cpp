#include "Node.h"
Node::Node(const Tile &tile,
           float heuristic)
    : tile(tile),
      heuristic(heuristic),
      distance(0),
      totalCost(heuristic) {
}
Node::Node(const Tile &tile, Node *parent, float distance,
           float heuristic)
    : tile(tile),
      heuristic(heuristic),
      parent(parent),
      distance(parent->distance + distance),
      totalCost(distance + heuristic) {
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

