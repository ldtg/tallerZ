#include "Node.h"
Node::Node(const Position &pos,
           unsigned long heuristic)
    : position(pos),
      heuristic(heuristic),
      distance(0),
      totalCost(heuristic){
}
Node::Node(const Position &pos, Node *parent,
           unsigned long heuristic)
    : position(pos),
      heuristic(heuristic),
      parent(parent),
      distance(parent->distance + pos.getWeight()),
      totalCost(distance + heuristic){
}
const Position &Node::getPosition() const {
  return position;
}
std::vector<Movement> Node::makePath() {
  std::vector<Movement> path;
  if (parent != nullptr) {
    std::vector<Movement> parentPath = parent->makePath();
    path.insert(path.end(), parentPath.begin(), parentPath.end());
  }
  return path;
}

bool Node::operator==(const Node &node) const {
  return this->position == node.position;
}


bool Node::isBetter(const Node &node) const{
  return this->totalCost < node.totalCost;
}
unsigned long Node::getTotalCost() const{
  return this->totalCost;
}
bool Node::hasPosition(const Position &position) const{
  return this->position == position;
}

