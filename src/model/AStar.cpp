#include <algorithm>
#include "AStar.h"
AStar::AStar(const Map &map, const Position &ipos, const Position &epos) : map(
    map), ipos(ipos), epos(epos) {
  Node *node = new Node(ipos, heuristic(ipos, epos));
  open.insert(node);
  createdNodes.push_back(node);
}
std::queue<Movement> AStar::find() {
  while (!open.begin()->second->hasPosition(epos)) {
    Node *current = open.begin()->second;
    open.erase(open.begin());
    for (Node *neighbor : getNeighbors(current)) {
      bool isInClose =
          std::find(close.begin(), close.end(), neighbor) != close.end();
      if (!existBetter(neighbor) && !isInClose)
        open.emplace(neighbor->getTotalCost(), neighbor);
    }
    close.push_back(current);
  }
  return makeQueue(open.begin()->second->makePath());
}
unsigned long AStar::heuristic(const Position &position,
                               const Position &epos) const {
  return position.chebyshevDistance(epos);
}
std::queue<Movement> AStar::makeQueue(std::vector<Movement> pathVector) {
  std::queue<Movement> path;
  for (Movement &mov : pathVector)
    path.push(mov);
  return path;
}

std::vector<Node *> AStar::getNeighbors(Node *current) {
  std::vector<Node *> vector;
  for (Position &position : map.getNeighbors(current->getPosition())) {
    Node *auxNode = new Node(position, current, heuristic(position, epos));
    vector.push_back(auxNode);
    createdNodes.push_back(auxNode);
  }
  return vector;
}
bool AStar::existBetter(Node *pNode) const {
  for (auto &par:open) {
    if (*par.second == *pNode && par.second->isBetter(*pNode))
      return true;
  }
  return false;
}
AStar::~AStar() {
  for (Node *node: createdNodes)
    delete node;
}
