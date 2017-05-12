#include <algorithm>
#include "AStar.h"
AStar::AStar(const Map &map, const Unit *unit, const Tile &etile)
    : map(map),
      unit(unit),
      itile(map.getTile(unit->getCurrentPosition())),
      etile(etile) {
  Node *node = new Node(itile, heuristic(itile, etile));
  open.emplace(node->getTotalCost(), node);
  createdNodes.push_back(node);
}
//Basado en http://web.mit.edu/eranki/www/tutorials/search/
//          http://theory.stanford.edu/~amitp/GameProgramming/
std::queue<Movement> AStar::find() {
  while (!open.begin()->second->hasTile(etile)) {
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
float AStar::heuristic(const Tile &itile,
                       const Tile &etile) const {
  return itile.getPosition().chebyshevDistance(etile.getPosition());
}
std::queue<Movement> AStar::makeQueue(std::vector<Movement> pathVector) {
  std::queue<Movement> path;
  for (Movement &mov : pathVector)
    path.push(mov);
  return path;
}

std::vector<Node *> AStar::getNeighbors(Node *current) {
  std::vector<Node *> vector;
  for (Tile &tile : map.getNeighbors(current->getTile())) {
    if (unit->canGoThrough(tile.getTerrainType()) && tile.isEmpty()) {
      Node *auxNode = new Node(tile,
                               current,
                               unit->getMovementCost(tile.getTerrainType()),
                               heuristic(tile, etile));
      vector.push_back(auxNode);
      createdNodes.push_back(auxNode);
    }
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
