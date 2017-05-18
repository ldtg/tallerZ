#include "GameCotroller.h"
#include "AStar.h"
#include "UnitMoveEvent.h"

void GameCotroller::move(UnitID &idunit, Position &position) {
  Unit *unit = units.at(idunit);
  AStar astar(map, unit, position);
  unit->move(astar.find());
}

void GameCotroller::attack(UnitID attackerId, UnitID attackedId) {
  Unit *attacker = units.at(attackerId);
  Attackable *attacked = units.at(attackedId);
  if (attacker->isInRange(attacked)
      && map.canPass(attacker->getCurrentPosition(),
                     attacked->getCurrentPosition())) {
    attacker->attack(attacked);
  } else {
    AStar astar(map, attacker, attacked->getCurrentPosition());
    attacker->hunt(astar.find(), attacked);
  }
}/*
void GameCotroller::attack(UnitID attackerId, BuildID attackedId) {
  Unit *attacker = units.at(attackerId);
  Attackable *attacked = builds.at(attackedId);
  if (attacker->isInRange(attacked)
      && map.canPass(attacker->getCurrentPosition(),
                     attacked->getCurrentPosition())) {
    attacker->attack(attacked);
  } else {
    AStar astar(map, attacker, attacked->getCurrentPosition());
    attacker->hunt(astar.find(), attacked);
  }
}

void GameCotroller::capture(UnitID idunit, Position position) {
  Unit *unit = units[idunit];
  AStar astar(map, unit, position);
  unit->capture(astar.find());
}*/

std::vector<Event *> GameCotroller::tick() {
  std::vector<Event *> events;
  for (auto it_units = units.begin(); it_units != units.end();
       ++it_units) {
    Unit *current = it_units->second;
    current->receiveDamages();
    if (current->isAlive()) {
      if (current->isMoving()) {
        this->move(current, events);
      }
      if (current->isHunting())
        this->hunt(current, events);
      if (current->isCapturing())
        this->capture(current, events);
    } else {
      //TODO: crear evento muerte
      //map.procces(event)
      delete current;
      it_units = units.erase(it_units);
    }
  }
  return events;
}
void GameCotroller::move(Unit *unit, std::vector<Event *> &events) {
  if (map.canPass(unit->getCurrentPosition(),
                  unit->nextMovePosition())) {
    //TODO: crear evento move
    float terrainFactor =
        map.getTile(unit->getCurrentPosition()).getTerrainData().terrainFactor;
    unit->doMoveWithSpeed(terrainFactor);
  }
}
void GameCotroller::hunt(Unit *unit, std::vector<Event *> &events) {
  Attackable *hunted = unit->getHunted();
  if (unit->attackedInRange()
      && map.canPass(unit->getCurrentPosition(),
                     hunted->getCurrentPosition())) {
    unit->doAttack();
    //TODO: crear evento attack
  } else {
    this->move(unit, events);
  }
  if (hunted->isMoving())
    unit->addMove(hunted->nextMovePosition()); //en vez de recalcular el path uso los movs del atacado
}
void GameCotroller::capture(Unit *unit, std::vector<Event *> &events) {
  if (unit->isStill()) { //llego
    //TODO: crear evento captura
    //this->newCapture(unit);
  } else {
    this->move(unit, events);
  }
}
