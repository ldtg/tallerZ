#include <algorithm>
#include "AStar.h"

AStar::AStar(const Map &map, const Unit *unit, const Position &target)
    : map(map),
      unit(unit),
      itile(map.getTile(unit->getCenterPosition())),
      etile(map.getTile(target)), target(target) {
  Node *node = new Node(itile, heuristic(itile, etile));
  open.emplace(node->getTotalCost(), node);
  createdNodes.push_back(node);
}

float AStar::heuristic(const Tile &itile,
                       const Tile &etile) const {
  return itile.getCenterPosition().chebyshevDistance(etile.getCenterPosition());
}

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

std::vector<Node *> AStar::getNeighbors(Node *current) {
  std::vector<Node *> vector;
  for (Tile &tile : map.getNeighbors(current->getTile())) {
    if (unit->canGoThrough(tile.getTerrainData())
        && (tile.isPassable() || tile == etile)) {
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

bool AStar::isInClose(Node *neighbor) {
  for (Node *node : close) {
    if (*node == *neighbor)
      return true;
  }
  return false;
}

AStar::~AStar() {
  for (Node *node: createdNodes)
    delete node;
}
