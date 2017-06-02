#include "Unit.h"
#include <algorithm>
#include <iostream>

Position Unit::getCenterPosition() const {
  return this->currentPosition;
}

void Unit::move(const std::vector<Position> &movementsPositions) {
  this->movementsPositions = movementsPositions;
  this->movState.moving();
}

void Unit::attack(Attackable *other) {
  this->movState.hunting();
  this->hunted = other;
}

bool Unit::isInRange(Attackable *other) {
  return this->currentPosition.euclideanDistance(other->getAttackPosition(
      currentPosition))
      < range;
}

void Unit::receiveAttack(const Weapon &weapon) {
  this->damagesToReceive.push_back(weapon.damage);
}

void Unit::hunt(const std::vector<Position> &movementsPositions,
                Attackable *other) {
  this->movementsPositions = movementsPositions;
  this->movState.hunting();
  this->hunted = other;
}

Position Unit::nextMovePosition() const {
  if (!movementsPositions.empty()) {
    Position aux = currentPosition;
    aux.move(movementsPositions.front());
    return aux;

  } else {
    return currentPosition;
  }
}

void Unit::receiveDamages() {
  for (unsigned short damage: damagesToReceive) {
    if (health > damage) {
      this->health -= damage;
    } else {
      this->health = 0;
      owner->subUnit();
    }
  }
  damagesToReceive.clear();
}

void Unit::doOneMove() {
  auto aux = movementsPositions.front();
  currentPosition.move(movementsPositions.front());
  if (currentPosition == movementsPositions.front()) {
    movementsPositions.erase(movementsPositions.begin());
  }
  if (movementsPositions.empty() && this->isMoving())
    this->movState.still();
}

bool Unit::attackedInRange() {
  return currentPosition.euclideanDistance(hunted->getAttackPosition(
      currentPosition))
      < range;
}

bool Unit::isHunting() {
  return this->movState.isHunting();
}

bool Unit::timeToAttack() {
  if (attackCounterActual == 0) {
    if (hunted->isAlive()) {
      attackCounterActual = attackCounterBase;
      return true;
    } else {
      this->still();
      return false;
    }
  } else {
    attackCounterActual--;
  }
  return false;
}
Attackable *Unit::getHunted() {
  return hunted;
}

Weapon Unit::getWeapon() {
  return this->weapon;
}
void Unit::capture(const std::vector<Position> &movementsPositions,
                   Capturable *capturable) {
  this->capturable = capturable;
  this->movementsPositions = movementsPositions;
  this->movState.capturing();
}
bool Unit::isCapturing() const {
  return this->movState.isCapturing();
}
bool Unit::isStill() const {
  return this->movState.isStill();
}
UnitID Unit::getId() const {
  return this->id;
}

bool Unit::isAlive() const {
  return health > 0;
}
bool Unit::isMoving() const {
  return movState.isMoving();
}
unsigned long Unit::getHealth() const {
  return health;
}

Unit::~Unit() {}

bool Unit::doMoveWithSpeed(float terrainFactor) {
  for (int i = 0; i < this->getMovementSpeed(terrainFactor); ++i) {
    doOneMove();
  }
  return this->movState.isStill();
}

void Unit::addMove(const Position &position) {
  if (std::find(movementsPositions.begin(), movementsPositions.end(), position)
      == movementsPositions.end())
    movementsPositions.push_back(position);
}

bool Unit::hasDamagesToReceive() const {
  return !damagesToReceive.empty();
}

Unit::Unit(const Position &current,
           const UnitData &data,
           Player &owner,
           Team &team)
    : owner(&owner), team(&team),
      currentPosition(current),
      weapon(data.weapon),
      attackCounterBase(data.ticksUntilFire),
      attackCounterActual(attackCounterBase),
      baseSpeed(data.speed),
      range(data.range),
      health(data.health),
      id(data.type),
      movState(),
      hunted(nullptr), capturable(nullptr) {

}

unsigned short Unit::getRange() const {
  return range;
}

bool Unit::canAttack(Attackable *attackable) {
  return this->team->isEnemy(attackable->getOwner().getID());
}

Bullet Unit::createBullet() {
  return Bullet(weapon, this->currentPosition, hunted);
}

void Unit::still() {
  this->movState.still();
  hunted = nullptr;
  movementsPositions.clear();
  attackCounterActual = attackCounterBase;
}

Position Unit::getAttackPosition(const Position &attacker) const {
  return currentPosition;
}
Player &Unit::getOwner() {
  return *owner;
}
Team &Unit::getOwnerTeam() {
  return *team;
}
bool Unit::hasMovesToDo() const {
  return !movementsPositions.empty();
}
void Unit::kill() {
  this->health = 0;
}
Capturable *Unit::getCapturable() {
  return capturable;
}
