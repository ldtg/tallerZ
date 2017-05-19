#include <algorithm>
#include "AStar.h"

AStar::AStar(const Map &map, const Unit *unit, const Position &target)
    : map(map),
      unit(unit),
      itile(map.getTile(unit->getCurrentPosition())),
      etile(map.getTile(target)), target(target) {
  Node *node = new Node(itile, heuristic(itile, etile));
  open.emplace(node->getTotalCost(), node);
  createdNodes.push_back(node);

}

//Basado en http://web.mit.edu/eranki/www/tutorials/search/
//          http://theory.stanford.edu/~amitp/GameProgramming/
std::vector<Position> AStar::find() {
  std::vector<Position> aux;
  while (!open.begin()->second->hasTile(etile)) { //suponemos que siempre hay un camino
    Node *current = open.begin()->second;
    open.erase(open.begin());
    for (Node *neighbor : getNeighbors(current)) {

      if (!existBetter(neighbor) && !isInClose(neighbor))
        open.emplace(neighbor->getTotalCost(), neighbor);
    }
    close.push_back(current);
  }
  aux = open.begin()->second->makePath();
  if (etile.getCenterPosition() != target)
    aux.push_back(target);
  return aux;
}
float AStar::heuristic(const Tile &itile,
                       const Tile &etile) const {
  return itile.getCenterPosition().chebyshevDistance(etile.getCenterPosition());
}

std::queue<Position> AStar::makeQueue(std::vector<Position> pathVector) {
  std::queue<Position> path;
  for (Position &pos : pathVector)
    path.push(pos);
  if (etile.getCenterPosition() != target)
    path.push(target);
  return path;
}

std::vector<Node *> AStar::getNeighbors(Node *current) {
  std::vector<Node *> vector;
  for (Tile &tile : map.getNeighbors(current->getTile())) {
    if (unit->canGoThrough(tile.getTerrainData()) && tile.isPassable()) {
      Node *auxNode = new Node(tile,
                               current,
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
bool AStar::isInClose(Node *neighbor) {
  for (Node *node : close) {
    if (*node == *neighbor)
      return true;
  }
  return false;
}


