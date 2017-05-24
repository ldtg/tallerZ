#include <iostream>
#include <chrono>
#include <thread>
#include "GameController.h"
#include "AStar.h"
#include "UnitMoveEvent.h"
#include "UnitDamageReceiveEvent.h"
#include "UnitAttackEvent.h"
#include "UnitDeathEvent.h"
#include "Data.h"
#include "UnitNotFoundException.h"

void GameController::move(const UnitID &idunit, const Position &position) {
  Unit *unit = units.at(idunit);
  AStar astar(map, unit, position);
  unit->move(astar.find());
}

void GameController::attack(const UnitID &attackerId,
                            const UnitID &attackedId) {
  Unit *attacker = units.at(attackerId);
  Attackable *attacked = units.at(attackedId);
  if(!attacker->canAttack(attacked))
    return;
  if (attacker->isInRange(attacked)
      && map.canPass(attacker->getCurrentPosition(),
                     attacked->getCurrentPosition())) {
    attacker->attack(attacked);
  } else {
    AStar astar(map, attacker, attacked->getCurrentPosition());
    attacker->hunt(astar.find(), attacked);
  }
}

/*
void GameController::attack(UnitID attackerId, BuildID attackedId) {
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

void GameController::capture(UnitID idunit, Position position) {
  Unit *unit = units[idunit];
  AStar astar(map, unit, position);
  unit->capture(astar.find());
}*/

std::vector<Event *> GameController::tick() {
  auto begin = std::chrono::high_resolution_clock::now();

  std::vector<Event *> events;
  this->doTick(events);

  auto end = std::chrono::high_resolution_clock::now();
  auto diff =
      std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
  std::this_thread::sleep_for(
      std::chrono::milliseconds(data.miliSecsPerTick) - diff);
  return events;
}

void GameController::doTick(std::vector<Event *> &events) {
  for (auto it_units = units.begin(); it_units != units.end();
       ++it_units) {
    Unit *current = it_units->second;
    if (current->hasDamagesToReceive()) {
      unitReceiveDamage(current, events);
    }
    if (current->isAlive()) {
      if (current->isMoving()) {
        move(current, events);
      }
      if (current->isHunting())
        hunt(current, events);
      if (current->isCapturing())
        capture(current, events);
      //para que ataquen auto a las que tienen cerca
      this->autoAttack(current);
    } else {
      events.push_back(new UnitDeathEvent(current->getId()));
      it_units = units.erase(it_units);
    }
  }
 // updateMap(events);
}

void GameController::unitReceiveDamage(Unit *current,
                                       std::vector<Event *> &events) const {
  current->receiveDamages();
  events.push_back(new UnitDamageReceiveEvent(current->getId(),
                                              current->getUnitState()));
}

void GameController::move(Unit *unit, std::vector<Event *> &events) const {
  if (map.canPass(unit->getCurrentPosition(),
                  unit->nextMovePosition())) {
    float terrainFactor =
        map.getTile(unit->getCurrentPosition()).getTerrainData().terrainFactor;
    unit->doMoveWithSpeed(terrainFactor);
    events.push_back(new UnitMoveEvent(unit->getId(), unit->getCurrentPosition()));
  }
}

void GameController::hunt(Unit *unit, std::vector<Event *> &events) const {
  Attackable *hunted = unit->getHunted();
  if (unit->attackedInRange()
      && map.canPass(unit->getCurrentPosition(),
                     hunted->getCurrentPosition())) {
    if (unit->doAttack())//mejorar
      events.push_back(new UnitAttackEvent(unit->getId(),
                                           hunted->getCurrentPosition()));
  } else {
    this->move(unit, events);
  }
  if (hunted->isMoving())
    unit->addMove(hunted->nextMovePosition()); //en vez de recalcular el path uso los movs del atacado
}

void GameController::capture(Unit *unit, std::vector<Event *> &events) const {
  if (unit->isStill()) { //llego
    //TODO: crear evento captura
    //this->newCapture(unit);
  } else {
    this->move(unit, events);
  }
}

GameController::GameController(Map &map,
                               const std::map<UnitID, Unit*> &units)
    : map(map), units(units) {}

void GameController::updateMap(std::vector<Event *> events) {
  for (auto &event : events) {
//    event->process(this->map);
  }
}

void GameController::removeDeaths(const std::vector<Unit *> &vector) {
  for (auto &unit : vector) {
    delete unit;
  }
}

void GameController::autoAttack(Unit *current) {
  for (auto &par:units) {
    if (current->isInRange(par.second) && current->getId() != par.first) {
      this->attack(current->getId(), par.second->getId());
    }
  }
}
