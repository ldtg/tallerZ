#include <iostream>
#include <chrono>
#include <thread>
#include <Exceptions/model_exceptions/UnableToFindAPathException.h>
#include <model/Events/model/BuildDestroyedEvent.h>
#include <model/Events/model/UnitCreateEvent.h>
#include <model/Events/model/BulletHitEvent.h>
#include <model/Events/model/CaptureEvent.h>
#include <model/Events/model/BulletMoveEvent.h>
#include <model/Events/model/UnitStillEvent.h>
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

void GameController::capture(UnitID idunit, Position position) {
  if (capturables.at(position)->canBeCapturedBy(idunit)) {
    Unit *unit = units.at(idunit);
    AStar astar(map, unit, position);
    unit->capture(astar.find());
  }
}

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
  for (auto it_units = units.begin(); it_units != units.end();) {

    Unit *current = it_units->second;

//    if (current->hasDamagesToReceive()) {
//      unitReceiveDamage(current, events);
//    }

    if (current->isAlive()) {
      if (current->isMoving())
        move(current, events, it_units);
      else if (current->isHunting())
        hunt(current, events, it_units);
      else if (current->isCapturing())
        capture(current, events, it_units);
      else if (current->isStill()) {
        autoAttack(current, it_units);
      }

      //El ++it_units esta adentro de los metodos porque el capture lo puede
      // modificar si tiene que hacer desaparecer a la unidad
    } else {
      events.push_back(new UnitDeathEvent(current->getId()));
      map.removeUnit(current->getId());
      deathUnits.push_back(current);
      it_units = units.erase(it_units);
    }

    if (current->hasDamagesToReceive()) {
      unitReceiveDamage(current, events);
    }

  }
}

void GameController::unitReceiveDamage(Unit *current,
                                       std::vector<Event *> &events) const {
  current->receiveDamages();
  events.push_back(new UnitDamageReceiveEvent(current->getId(),
                                              current->getUnitState()));
  map.updateUnit(current->getId(), current->getUnitState());
}

void GameController::move(Unit *unit,
                          std::vector<Event *> &events,
                          std::map<UnitID, Unit *>::iterator &it) {
  if (map.canPass(unit->getCurrentPosition(),
                  unit->nextMovePosition())) {
    float terrainFactor =
        map.getTile(unit->getCurrentPosition()).getTerrainData().terrainFactor;
    bool still = unit->doMoveWithSpeed(terrainFactor);
    events.push_back(new UnitMoveEvent(unit->getId(),
                                       unit->getCurrentPosition()));
    map.updateUnit(unit->getId(), unit->getUnitState());

    if (still) {
      events.push_back(new UnitStopAttackEvent(unit->getId()));
    }

  } else {
    unit->still();
  }
  ++it;
}

bool noEntro=true;

void GameController::hunt(Unit *unit,
                          std::vector<Event *> &events,
                          std::map<UnitID, Unit *>::iterator &it) {
  Attackable *hunted = unit->getHunted();

  if (!hunted->isAlive()) {
    events.push_back(new UnitStopAttackEvent(unit->getId()));
    unit->still();
    return;
  }

  if (unit->attackedInRange()
      && map.canPass(unit->getCurrentPosition(),
                     hunted->getAttackPosition(unit->getCurrentPosition()))) {
    if (unit->timeToAttack()) {
      if (noEntro) {
        noEntro = false;
        events.push_back(new UnitAttackEvent(unit->getId()));
      }
      this->bullets.push_back(unit->createBullet());
      events.push_back(new BulletNewEvent(this->bullets.front()));
    }
    ++it;
  } else {
    this->move(unit, events, it);
  }

  if (hunted->isMoving())
    //en vez de recalcular el path uso los movs del atacado
    unit->addMove(hunted->nextMovePosition());
}

void GameController::capture(Unit *unit,
                             std::vector<Event *> &events,
                             std::map<UnitID, Unit *>::iterator &it) {
  if (!unit->hasMovesToDo()) { //llego
    unit->still();
    Capturable *capturable = this->capturables.at(unit->getCurrentPosition());
    capturable->capture(unit->getId(), unit->getOwner(), unit->getOwnerTeam());
    std::map<BuildID, BuildState>
        capturedBuilds = capturable->getCapturedBuilds();
    std::map<UnitID, UnitState> capturedUnits = capturable->getCapturedUnits();
    bool dissapear = capturable->capturerDissapear();
    //update map
    for (auto par: capturedBuilds) {
      map.updateBuild(par.first, par.second);
    }
    for (auto par: capturedUnits) {
      map.updateUnit(par.first, par.second);
    }
    //create event
    events.push_back(new CaptureEvent(unit->getId(),
                                      capturedBuilds,
                                      capturedUnits,
                                      dissapear));
    if (dissapear) {
      // si alguien la estaba persiguiendo la tiene que ver muerta,
      // pero no se tiene que disparar el evento muerte
      unit->kill();
      map.removeUnit(unit->getId());
      deathUnits.push_back(unit);
      it = units.erase(it);
    } else {
      ++it;
    }
    if (!capturable->isRecapturable()) {
      this->capturables.erase(capturable->getCapturePosition());
      delete capturable;
    }

  } else {
    this->move(unit, events, it);
    ++it;
  }
}

void GameController::autoAttack(Unit *current,
                                std::map<UnitID, Unit *>::iterator &it) {
/*
  for (auto &par: units) {
    if (current->isInRange(par.second)
        && current->getId() != par.first) {
      this->attack(current->getId(), par.second->getId());
    }
  }
*/
  ++it;
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
      vector.push_back(new BulletMoveEvent(current));
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
GameController::GameController(Map &map,
                               const std::map<UnitID, Unit *> &units,
                               const std::map<BuildID, Build *> &builds,
                               const std::map<Position,
                                              Capturable *> &capturables) : map(
    map), units(units), builds(builds), capturables(capturables) {

}

