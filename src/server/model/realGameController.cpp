#include "realGameController.h"
#include <thread>
#include <server/model/Events/Bullet/serverBLTHitEvent.h>
#include <server/model/Events/Bullet/serverBLTMoveEvent.h>
#include <server/model/Events/Unit/serverUMoveEvent.h>
#include <server/model/Events/Unit/serverUStillEvent.h>
#include <server/model/Events/Unit/serverUAttackEvent.h>
#include <server/model/Events/Bullet/serverBLTNewEvent.h>
#include <server/model/Events/Capturable/serverCCaptureEvent.h>
#include <server/model/Events/Build/serverBDestroyedEvent.h>
#include <server/model/Events/Build/serverBDamageEvent.h>
#include <server/model/Events/Game/serverGEndGameEvent.h>
#include <server/model/Events/Unit/serverUCreateEvent.h>
#include <server/model/Events/TerrainObject/serverTODestroyedEvent.h>
#include <server/model/Events/Unit/serverUDeathEvent.h>
#include <server/model/Events/Game/serverGPlayerDefeatedEvent.h>
#include "AStar.h"

#include "Data.h"

void realGameController::move(const UnitID &idunit, const Position &position) {
  Unit *unit = units.at(idunit);
  Tile etile = map.getTile(position);
  if (!unit->canGoThrough(etile.getTerrainData()) || !etile.isPassable())
    return;
  AStar astar(map, unit, position);
  unit->move(astar.find());

}

void realGameController::attack(const UnitID &attackerId,
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

void realGameController::attack(const UnitID &attackerId,
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

void realGameController::attack(const UnitID &attackerID,
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

void realGameController::changeUnitFab(const BuildID &buildId,
                                       const UnitType &type) {
  builds.at(buildId)->changeFabUnit(type);

}

void realGameController::capture(const UnitID &idunit,
                                 const CapturableID &capturableID) {
  Capturable *capturable = capturables.at(capturableID);
  if (capturable->canBeCapturedBy(idunit)) {
    Unit *unit = units.at(idunit);
    AStar astar(map, unit, capturable->getCapturePosition());
    unit->capture(astar.find(), capturable);
  }
}

void realGameController::tick() {
  auto begin = std::chrono::high_resolution_clock::now();

  this->doTick();

  auto end = std::chrono::high_resolution_clock::now();
  auto diff =
      std::chrono::duration_cast<std::chrono::duration<float>>(end - begin);
  auto sleepTime = std::chrono::milliseconds(data.miliSecsPerTick) - diff;
  std::this_thread::sleep_for(sleepTime);
}

void realGameController::doTick() {
  bulletsTick();
  unitsTick();
  buildsTick();
  objectsTick();
  /*PlayersTick();
  TeamsTick();*/
}

void realGameController::unitsTick() {
  for (auto it_units = units.begin(); it_units != units.end();) {
    Unit *current = it_units->second;
    if (!current->getOwner()->getID().isGaia()) {
      if (current->hasDamagesToReceive()) {
        unitReceiveDamage(current);
      }

      if (current->isAlive()) {
        if (current->isMoving())
          move(current, it_units);
        else if (current->isAttacking())
          hunt(current, it_units);
        else if (current->isCapturing())
          capture(current, it_units);
        else if (current->isStill()) {
          autoAttack(current, it_units);
        }

        //El ++it_units esta adentro de los metodos porque el capture lo puede
        // modificar si tiene que hacer desaparecer a la unidad
      } else {
        eventQueue.push(new serverUDeathEvent(current->getId()));
        map.removeUnit(current->getId());
        deathUnits.push_back(current);
        it_units = units.erase(it_units);
      }
    } else {
      ++it_units;
    }

  }
}

void realGameController::unitReceiveDamage(Unit *current) const {
  current->receiveDamages();
  map.updateUnit(current->getId(), current->getUnitState());
  //el evento damage receive no se usaba
}

void realGameController::move(Unit *unit,
                              std::map<UnitID, Unit *>::iterator &it) {
  if (map.canPass(unit->getCenterPosition(),
                  unit->nextMovePosition())) {
    float terrainFactor =
        map.getTile(unit->getCenterPosition()).getTerrainData().terrainFactor;
    bool still = unit->doMoveWithSpeed(terrainFactor);
    eventQueue.push(new serverUMoveEvent(unit->getId(),
                                         unit->getCenterPosition()));
    map.updateUnit(unit->getId(), unit->getUnitState());

    if (still) {
      eventQueue.push(new serverUStillEvent(unit->getId()));
    }

  } else {
    unit->still();
  }
  ++it;
}

void realGameController::hunt(Unit *unit,
                              std::map<UnitID, Unit *>::iterator &it) {
  Attackable *hunted = unit->getHunted();

  if (!hunted->isAlive()) {
    eventQueue.push(new serverUStillEvent(unit->getId()));
    unit->still();
    return;
  }

  Position huntedPos = hunted->getAttackPosition(unit->getCenterPosition());
  Position unitPos = unit->getCenterPosition();

  if (unit->attackedInRange()
      && map.canPass(unitPos, huntedPos))
  {
    if (unit->isFirstAttack()) {
      Position huntedPos = hunted->getAttackPosition(unitPos);
      Position attackerPos = unit->getCenterPosition();

      eventQueue.push(new serverUAttackEvent(unit->getId(),
                                             huntedPos,
                                             attackerPos));
    }
    if (unit->timeToAttack()) {
      this->bullets.push_back(unit->createBullet());

      eventQueue.push(new serverBLTNewEvent(this->bullets.front().getId(),
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
      eventQueue.push(new serverUStillEvent(unit->getId()));
    } else {
      this->move(unit, it);
      if (hunted->isMoving())
        unit->addMove(hunted->nextMovePosition());
    }
  }
}

void realGameController::capture(Unit *unit,
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
    eventQueue.push(new serverUStillEvent(unit->getId()));

    eventQueue.push(new serverCCaptureEvent(unit->getId(), capturable->getID(),
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
    this->move(unit, it);
    ++it;
  }
}

void realGameController::autoAttack(Unit *current,
                                    std::map<UnitID, Unit *>::iterator &it) {

  for (auto &par: units) {
    if (current->isInRange(par.second)
        && current->getId() != par.first && current->canAttack(par.second)) {
      current->autoAttack(par.second);
    }
  }

  ++it;
}

void realGameController::bulletsTick() {
  for (std::vector<Bullet>::iterator iterator = bullets.begin();
       iterator != bullets.end();) {
    Bullet &current = *iterator;
    current.move();
    if (current.didHit()) {
      current.doHit();

      eventQueue.push(new serverBLTHitEvent(current.getId(), current.getTo(),
                                            current.getWeapon().type));
      map.removeBullet(current.getId());
      iterator = bullets.erase(iterator);
    } else {
      map.updateBullet(current.getId(), current.getState());
      eventQueue.push(new serverBLTMoveEvent(current.getId(), current.getTo()));
      ++iterator;
    }
  }
}

void realGameController::buildsTick() {
  for (auto b_iter = builds.begin(); b_iter != builds.end();) {
    Build *current = b_iter->second;
    if (!current->getOwner()->getID().isGaia()) {
      if (current->hasDamagesToReceive())
        buildReceiveDamage(current);

      if (current->isAlive()) {
        if (current->hasToBuild()) {
          this->addUnits(current->fabricateUnits(map.getNeighborFreePos(current->getCenterPosition())));
        }
        map.updateBuild(current->getId(), current->getBuildState());
        current->tick();
        b_iter++;
      } else {
        eventQueue.push(new serverBDestroyedEvent(current->getId()));
        map.updateBuild(current->getId(), current->getBuildState());
        b_iter = builds.erase(b_iter);
      }
    } else {
      ++b_iter;
    }
  }
}

void realGameController::buildReceiveDamage(Build *current) {
  current->receiveDamages();
  eventQueue.push(new serverBDamageEvent(current->getId(),
                                         current->getBuildState()));
}

void realGameController::PlayersTick() {
  for (auto &player : players) {
    if (!player.second->isAlive()) {
      eventQueue.push(new serverGPlayerDefeatedEvent(player.first));
    }
  }
}

void realGameController::TeamsTick() {
  unsigned short count = 0;
  const TeamID *winnerId = nullptr;
  for (auto &team : teams) {
    if (team.second.isTeamAlive()) {
      count++;
      winnerId = &team.first;
    }
  }
  if (count == 1) {
    eventQueue.push(new serverGEndGameEvent(*winnerId));
    this->endGame();
  }

}

void realGameController::addUnits(std::vector<Unit *> vector) {
  for (Unit *unit : vector) {
    units.emplace(unit->getId(), unit);
    map.addUnit(unit->getId(), unit->getUnitState());
    eventQueue.push(new serverUCreateEvent(unit->getId(),
                                           unit->getUnitState()));
  }
}

void realGameController::objectsTick() {
  for (auto t_it = terrainObjects.begin();
       t_it != terrainObjects.end();) {
    TerrainObject &current = t_it->second;
    if (current.hasDamagesToReceive()) {
      current.receiveDamages();
      map.updateTerrainObject(current.getID(), current.getState());
    }
    if (!current.isAlive()) {
      eventQueue.push(new serverTODestroyedEvent(current.getID()));
      t_it = terrainObjects.erase(t_it);
    } else {
      ++t_it;
    }
  }
}

realGameController::~realGameController() {
  for (auto &par : units) {
    delete par.second;
  }
  for (Unit *unit : deathUnits) {
    delete unit;
  }
  for (auto &par : builds) {
    delete (par.second);
  }
  for (auto &par : capturables) {
    delete (par.second);
  }
  for (auto &par : players) {
    delete (par.second);
  }
}
void realGameController::startGame() {
  gameInProgress = true;
}
void realGameController::endGame() {
  gameInProgress = false;
}
bool realGameController::isGameEnded() const {
  return !gameInProgress;
}
realGameController::realGameController(Map &map,
                                       const Game_Loader &game_loader,
                                       Queue<serverEvent *> &evqueue)
    : map(map), eventQueue(evqueue) {
  this->units = game_loader.get_controller_units();
  this->builds = game_loader.get_builds();
  this->capturables = game_loader.get_controller_capturables();
  this->terrainObjects = game_loader.get_controller_terrainObjects();
  this->players = game_loader.get_players();
  this->teams = game_loader.get_teams();
}

