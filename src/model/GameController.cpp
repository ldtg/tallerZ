#include <iostream>
#include <chrono>
#include <thread>
#include <Exceptions/model_exceptions/UnableToFindAPathException.h>
#include <model/Events/model/BuildDestroyedEvent.h>
#include <model/Events/model/UnitCreateEvent.h>
#include <model/Events/model/BulletHitEvent.h>
#include "GameController.h"
#include "AStar.h"
#include "model/Events/model/UnitMoveEvent.h"
#include "model/Events/model/UnitDamageReceiveEvent.h"
#include "model/Events/model/UnitAttackEvent.h"
#include "model/Events/model/UnitDeathEvent.h"
#include "Data.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"
#include "model/Events/model/BulletNewEvent.h"
#include "model/Events/model/BuildDamageEvent.h"
#include "UnitFactory.h"

void GameController::move(const UnitID &idunit, const Position &position) {
  Unit *unit = units.at(idunit);
  try {
    AStar astar(map, unit, position);
    unit->move(astar.find());
  } catch (const UnableToFindAPathException &e) {
    return;
  }

}

void GameController::attack(const UnitID &attackerId,
                            const UnitID &attackedId) {
  Unit *attacker = units.at(attackerId);
  Attackable *attacked = units.at(attackedId);
  if (!attacker->canAttack(attacked))
    return;
  if (attacker->isInRange(attacked)
      && map.canPass(attacker->getCurrentPosition(),
                     attacked->getAttackPosition(attacker->getCurrentPosition()))) {
    attacker->attack(attacked);
  } else {
    AStar astar(map,
                attacker,
                attacked->getAttackPosition(attacker->getCurrentPosition()));
    attacker->hunt(astar.find(), attacked);
  }
}

void GameController::attack(const UnitID &attackerId,
                            const BuildID &attackedId) {
  Unit *attacker = units.at(attackerId);
  Build *attacked = builds.at(attackedId);
  if (!attacker->canAttack(attacked))
    return;
  if (attacker->isInRange(attacked)
      && map.canPass(attacker->getCurrentPosition(),
                     attacked->getCenterPosition())) {
    attacker->attack(attacked);
  } else {
    AStar astar(map,
                attacker,
                attacked->getAttackPosition(attacker->getCurrentPosition()));
    attacker->hunt(astar.find(), attacked);
  }
}

void GameController::changeUnitFab(const BuildID &buildId,
                                   const UnitType &type) {
  builds.at(buildId)->changeFabUnit(type);

}

/*
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
      std::chrono::duration_cast<std::chrono::duration<float>>(end - begin);
  auto sleepTime = std::chrono::milliseconds(data.miliSecsPerTick) - diff;
  std::this_thread::sleep_for(sleepTime);
  return events;
}

void GameController::doTick(std::vector<Event *> &events) {
  bulletsTick(events);
  unitsTick(events);
  buildsTick(events);
}

void GameController::unitsTick(std::vector<Event *> &events) {
  for (auto it_units = units.begin(); it_units != units.end();
      ) {
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
      autoAttack(current);
      map.updateUnit(current->getId(), current->getUnitState());
      ++it_units;
    } else {
      events.push_back(new UnitDeathEvent(current->getId()));
      map.removeUnit(current->getId());
      deathUnits.push_back(current);
      it_units = units.erase(it_units);
    }
  }
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
    events.push_back(new UnitMoveEvent(unit->getId(),
                                       unit->getCurrentPosition()));
  } else {
    unit->still();
  }
}

void GameController::hunt(Unit *unit, std::vector<Event *> &events) {
  Attackable *hunted = unit->getHunted();
  if (unit->attackedInRange()
      && map.canPass(unit->getCurrentPosition(),
                     hunted->getAttackPosition(unit->getCurrentPosition()))) {
    if (unit->timeToAttack()) {
      this->bullets.push_back(unit->createBullet());
      events.push_back(new BulletNewEvent(this->bullets.front()));
    }
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

void GameController::autoAttack(Unit *current) {
  for (auto &par:units) {
    if (current->isStill() && current->isInRange(par.second)
        && current->getId() != par.first) {
      this->attack(current->getId(), par.second->getId());
    }
  }
}

void GameController::bulletsTick(std::vector<Event *> &vector) {
  for (std::vector<Bullet>::iterator iterator = bullets.begin();
       iterator != bullets.end();) {
    Bullet &current = *iterator;
    current.move();
    if (current.didHit()) {
      current.doHit();
      vector.push_back(new BulletHitEvent(current));
      map.removeBullet(current.getId());
      iterator = bullets.erase(iterator);
    } else {
      map.updateBullet(current.getId(), current.getState());
      ++iterator;
    }
  }
}

void GameController::buildsTick(std::vector<Event *> &events) {
  for (auto b_iter = builds.begin(); b_iter != builds.end();) {
    Build *current = b_iter->second;
    if (current->hasDamagesToReceive())
      buildReceiveDamage(current, events);
    if (current->isAlive()) {
      if (current->hasToBuild()) {
        this->addUnits(current->fabricateUnits(), events);
      }
      map.updateBuild(current->getId(), current->getBuildState());
      current->tick();
      b_iter++;
    } else {
      events.push_back(new BuildDestroyedEvent(current->getId()));
      map.updateBuild(current->getId(), current->getBuildState());
      b_iter = builds.erase(b_iter);
    }
  }

}

void GameController::buildReceiveDamage(Build *current,
                                        std::vector<Event *> &events) {
  current->receiveDamages();
  events.push_back(new BuildDamageEvent(current->getId(),
                                        current->getBuildState()));
}

GameController::~GameController() {
  for (auto &par : units) {
    delete par.second;
  }
  for (Unit *unit : deathUnits) {
    delete unit;
  }
  for (auto &par : builds) {
    delete (par.second);
  }
}

void GameController::addUnits(std::vector<Unit *> vector,
                              std::vector<Event *> &events) {
  for (Unit *unit : vector) {
    units.emplace(unit->getId(), unit);
    map.addUnit(unit->getId(), unit->getUnitState());
    events.push_back(new UnitCreateEvent(unit->getId(), unit->getUnitState()));
  }
}

GameController::GameController(Map &map,
                               const std::map<UnitID, Unit *> &units,
                               const std::map<BuildID, Build *> &builds)
    : map(map), units(units), builds(builds) {}

GameController::GameController(Map &map,
                               const std::map<UnitID, Unit *> &units)
    : map(map), units(units) {}

