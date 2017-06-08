#include <iostream>
#include <chrono>
#include <thread>
#include <Exceptions/model_exceptions/UnableToFindAPathException.h>
#include <client/model/Events/model/build/BuildDestroyedEvent.h>
#include <client/model/Events/model/unit/UnitCreateEvent.h>
#include <client/model/Events/model/bullet/BulletHitEvent.h>
#include <client/model/Events/model/CaptureEvent.h>
#include <client/model/Events/model/bullet/BulletMoveEvent.h>
#include <client/model/Events/model/unit/UnitStillEvent.h>
#include <client/model/Events/model/PlayerDefeatedEvent.h>
#include <client/model/Events/model/EndGameEvent.h>
#include <client/model/Events/model/TerrainObjectDestroyedEvent.h>
#include "client/model/Events/model/bullet/BulletNewEvent.h"
#include "client/model/Events/model/build/BuildDamageEvent.h"
#include "client/model/Events/model/unit/UnitMoveEvent.h"
#include "client/model/Events/model/unit/UnitDamageReceiveEvent.h"
#include "client/model/Events/model/unit/UnitAttackEvent.h"
#include "client/model/Events/model/unit/UnitDeathEvent.h"
#include "GameController.h"
#include "AStar.h"

#include "Data.h"
#include "Exceptions/model_exceptions/UnitNotFoundException.h"

#include "UnitFactory.h"

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
                               const std::map<CapturableID,
                                              Capturable *> &capturables)
    : map(map), units(units),
      builds(builds), capturables(capturables) {}

GameController::GameController(Map &map,
                               const std::map<UnitID, Unit *> &units,
                               const std::map<BuildID, Build *> &builds,
                               const std::map<CapturableID,
                                              Capturable *> &capturables,
                               const std::map<TerrainObjectID,
                                              TerrainObject> &terrainObjects)
    : map(map), units(units),
      builds(builds),
      capturables(capturables),
      terrainObjects(terrainObjects) {}

GameController::GameController(Map &map,
                               const std::map<UnitID, Unit *> &units,
                               const std::map<BuildID, Build *> &builds,
                               const std::map<CapturableID,
                                              Capturable *> &capturables,
                               const std::map<TerrainObjectID,
                                              TerrainObject> &terrainObjects,
                               const std::map<PlayerID, Player *> &players,
                               const std::map<TeamID, Team> &teams) :
    map(map), units(units),
    builds(builds),
    capturables(capturables),
    terrainObjects(terrainObjects),
    players(players), teams(teams) {}

void GameController::move(const UnitID &idunit, const Position &position) {
  Unit *unit = units.at(idunit);
  Tile etile = map.getTile(position);
  if (!unit->canGoThrough(etile.getTerrainData()) || !etile.isPassable())
    return;
  AStar astar(map, unit, position);
  unit->move(astar.find());

}

void GameController::attack(const UnitID &attackerId,
                            const UnitID &attackedId) {
  Unit *attacker;
  Attackable *attacked;
  try {
    attacker = units.at(attackerId);
    attacked = units.at(attackedId);
  } catch (const std::exception &e) {
    return;
  }

  if (!attacker->canAttack(attacked))
    return;

  if (attacker->isInRange(attacked)
      && map.canPass(attacker->getCenterPosition(),
                     attacked->getCenterPosition())) {
    attacker->attack(attacked);
  } else {
    AStar astar(map,
                attacker,
                attacked->getCenterPosition());
    attacker->hunt(astar.find(), attacked);
  }
}

void GameController::attack(const UnitID &attackerId,
                            const BuildID &attackedId) {
  Unit *attacker;
  Build *attacked;
  try {
    attacker = units.at(attackerId);
    attacked = builds.at(attackedId);
  } catch (const std::exception &e) {
    return;
  }
  if (!attacker->canAttack(attacked))
    return;

  if (attacker->isInRange(attacked)
      && map.canPass(attacker->getCenterPosition(),
                     attacked->getCenterPosition())) {
    attacker->attack(attacked);
  } else {
    AStar astar(map,
                attacker,
                attacked->getCenterPosition());
    attacker->hunt(astar.find(), attacked);
  }
}

void GameController::attack(const UnitID &attackerID,
                            const TerrainObjectID &attackedID) {
  Unit *attacker;
  TerrainObject *attacked;
  try {
    attacker = units.at(attackerID);
    attacked = &terrainObjects.at(attackedID);
  } catch (const std::exception &e) {
    return;
  }

  if (!attacker->canAttack(attacked))
    return;

  if (attacker->isInRange(attacked)
      && map.canPass(attacker->getCenterPosition(),
                     attacked->getCenterPosition())) {
    attacker->attack(attacked);
  } else {
    AStar astar(map,
                attacker,
                attacked->getCenterPosition());
    attacker->hunt(astar.find(), attacked);
  }
}

void GameController::changeUnitFab(const BuildID &buildId,
                                   const UnitType &type) {
  builds.at(buildId)->changeFabUnit(type);

}

void GameController::capture(const UnitID &idunit,
                             const CapturableID &capturableID) {
  Capturable *capturable = capturables.at(capturableID);
  if (capturable->canBeCapturedBy(idunit)) {
    Unit *unit = units.at(idunit);
    AStar astar(map, unit, capturable->getCapturePosition());
    unit->capture(astar.find(), capturable);
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
  objectsTick(events);
  PlayersTick(events);
  TeamsTick(events);
}

void GameController::unitsTick(std::vector<Event *> &events) {
  for (auto it_units = units.begin(); it_units != units.end();) {
    Unit *current = it_units->second;
    if (!current->getOwner()->getID().isGaia()) {
      if (current->hasDamagesToReceive()) {
        unitReceiveDamage(current, events);
      }

      if (current->isAlive()) {
        if (current->isMoving())
          move(current, events, it_units);
        else if (current->isAttacking())
          hunt(current, events, it_units);
        else if (current->isCapturing())
          capture(current, events, it_units);
        else if (current->isStill()) {
          autoAttack(current, events, it_units);
        }

        //El ++it_units esta adentro de los metodos porque el capture lo puede
        // modificar si tiene que hacer desaparecer a la unidad
      } else {
        events.push_back(new UnitDeathEvent(current->getId()));
        map.removeUnit(current->getId());
        deathUnits.push_back(current);
        it_units = units.erase(it_units);
      }
    } else {
      ++it_units;
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
  if (map.canPass(unit->getCenterPosition(),
                  unit->nextMovePosition())) {
    float terrainFactor =
        map.getTile(unit->getCenterPosition()).getTerrainData().terrainFactor;
    bool still = unit->doMoveWithSpeed(terrainFactor);
    events.push_back(new UnitMoveEvent(unit->getId(),
                                       unit->getCenterPosition()));
    map.updateUnit(unit->getId(), unit->getUnitState());

    if (still) {
      events.push_back(new UnitStillEvent(unit->getId()));
    }

  } else {
    unit->still();
  }
  ++it;
}

void GameController::hunt(Unit *unit,
                          std::vector<Event *> &events,
                          std::map<UnitID, Unit *>::iterator &it) {
  Attackable *hunted = unit->getHunted();

  if (!hunted->isAlive()) {
    events.push_back(new UnitStillEvent(unit->getId()));
    unit->still();
    return;
  }

  if (unit->attackedInRange()
      && map.canPass(unit->getCenterPosition(),
                     hunted->getAttackPosition(unit->getCenterPosition()))) {
    if (unit->isFirstAttack()) {
      Position huntedPos = hunted->getAttackPosition(unit->getCenterPosition());
      Position attackerPos = unit->getCenterPosition();
      events.push_back(new UnitAttackEvent(unit->getId(),
                                           huntedPos,
                                           attackerPos));
    }
    if (unit->timeToAttack()) {
      this->bullets.push_back(unit->createBullet());
      events.push_back(new BulletNewEvent(this->bullets.front().getId(),
                                          this->bullets.front().getWeapon().type,
                                          this->bullets.front().getFrom(),
                                          this->bullets.front().getTo()));
    }
    if (hunted->isMoving()) {
      unit->addMove(hunted->nextMovePosition());
    }
    ++it;
  } else {
    if (unit->isAutoAttacking()) {
      unit->still();
      events.push_back(new UnitStillEvent(unit->getId()));
    } else {
      this->move(unit, events, it);
      if (hunted->isMoving())
        unit->addMove(hunted->nextMovePosition());
    }
  }
}

void GameController::capture(Unit *unit,
                             std::vector<Event *> &events,
                             std::map<UnitID, Unit *>::iterator &it) {
//  if (!unit->hasMovesToDo()) { //llego
  if (unit->capturableInRange()) {
    unit->still();
    Capturable *capturable = unit->getCapturable();

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
    events.push_back(new UnitStillEvent(unit->getId()));

    events.push_back(new CaptureEvent(unit->getId(), capturable->getID(),
                                      capturable->getCapturePosition(),
                                      capturedBuilds,
                                      capturedUnits, dissapear));
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
      this->capturables.erase(capturable->getID());
      map.removeCapturable(capturable->getID());
      delete capturable;
    } else {
      map.updateCapturable(capturable->getID(),
                           capturable->getCapturableState());
    }

  } else {
    this->move(unit, events, it);
    ++it;
  }
}

void GameController::autoAttack(Unit *current, std::vector<Event *> &events,
                                std::map<UnitID, Unit *>::iterator &it) {

  for (auto &par: units) {
    if (current->isInRange(par.second)
        && current->getId() != par.first && current->canAttack(par.second)) {
      current->autoAttack(par.second);
    }
  }

  ++it;
}

void GameController::bulletsTick(std::vector<Event *> &vector) {
  for (std::vector<Bullet>::iterator iterator = bullets.begin();
       iterator != bullets.end();) {
    Bullet &current = *iterator;
    current.move();
    if (current.didHit()) {
      current.doHit();
      vector.push_back(new BulletHitEvent(current.getId(),
                                          current.getWeapon().type));
      map.removeBullet(current.getId());
      iterator = bullets.erase(iterator);
    } else {
      map.updateBullet(current.getId(), current.getState());
      vector.push_back(new BulletMoveEvent(current.getId(), current.getTo()));
      ++iterator;
    }
  }
}

void GameController::buildsTick(std::vector<Event *> &events) {
  for (auto b_iter = builds.begin(); b_iter != builds.end();) {
    Build *current = b_iter->second;
    if (!current->getOwner()->getID().isGaia()) {
      if (current->hasDamagesToReceive())
        buildReceiveDamage(current, events);

      if (current->isAlive()) {
        if (current->hasToBuild()) {
          this->addUnits(current->fabricateUnits(map.getNeighborFreePos(current->getCenterPosition())),
                         events);
        }
        map.updateBuild(current->getId(), current->getBuildState());
        current->tick();
        b_iter++;
      } else {
        events.push_back(new BuildDestroyedEvent(current->getId()));
        map.updateBuild(current->getId(), current->getBuildState());
        b_iter = builds.erase(b_iter);
      }
    } else {
      ++b_iter;
    }
  }
}

void GameController::buildReceiveDamage(Build *current,
                                        std::vector<Event *> &events) {
  current->receiveDamages();
  events.push_back(new BuildDamageEvent(current->getId(),
                                        current->getBuildState()));
}

void GameController::PlayersTick(std::vector<Event *> &events) {
  for (auto &player : players) {
    if (!player.second->isAlive())
      events.push_back(new PlayerDefeatedEvent(player.first));
  }
}

void GameController::TeamsTick(std::vector<Event *> &events) {
  unsigned short count = 0;
  const TeamID *winnerId = nullptr;
  for (auto &team : teams) {
    if (team.second.isTeamAlive()) {
      count++;
      winnerId = &team.first;
    }
  }
  if (count == 1) {
    events.push_back(new EndGameEvent(*winnerId));
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

void GameController::objectsTick(std::vector<Event *> &events) {
  for (auto t_it = terrainObjects.begin();
       t_it != terrainObjects.end();) {
    TerrainObject &current = t_it->second;
    if (current.hasDamagesToReceive()) {
      current.receiveDamages();
      map.updateTerrainObject(current.getID(), current.getState());
    }
    if (!current.isAlive()) {
      events.push_back(new TerrainObjectDestroyedEvent(current.getID()));
      t_it = terrainObjects.erase(t_it);
    } else {
      ++t_it;
    }
  }
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
