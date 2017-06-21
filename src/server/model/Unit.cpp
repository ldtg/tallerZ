#include "Unit.h"
#include "Data.h"
#include <algorithm>

Unit::Unit(const Position &current,
           const UnitData &unitData,
           Player &owner,
           const Team &team)
    : owner(&owner), team(team),
      currentPosition(current),
      weapon(unitData.weapon),
      attackCounterBase(data.getTickAmount(unitData.secsUntilFire)),
      attackCounterActual(attackCounterBase),
      baseSpeed(unitData.speed),
      range(unitData.range * data.rangeMultipliquer),
      health(unitData.health),
      id(unitData.type),
      movState(), firstAttack(true),
      hunted(nullptr), capturable(nullptr) {}

void Unit::move(const std::vector<Position> &movementsPositions) {
  this->movementsPositions = movementsPositions;
  this->movState.moving();
}

void Unit::capture(const std::vector<Position> &movementsPositions,
                   Capturable *capturable) {
  this->capturable = capturable;
  this->movementsPositions = movementsPositions;
  this->movState.capturing();
}

void Unit::hunt(const std::vector<Position> &movementsPositions,
                Attackable *other) {
  this->movementsPositions = movementsPositions;
  this->movState.hunting();
  this->hunted = other;
  this->firstAttack = true;
  this->attackCounterActual = this->attackCounterBase;
}

void Unit::attack(Attackable *other) {
  this->movState.hunting();
  this->hunted = other;
  this->firstAttack = true;
  this->attackCounterActual = this->attackCounterBase;
}

void Unit::autoAttack(Attackable *hunted) {
  this->movState.autoAttacking();
  this->hunted = hunted;
  this->firstAttack = true;
  this->attackCounterActual = this->attackCounterBase;
}

void Unit::doMoveWithSpeed(float terrainFactor) {
  for (int i = 0; i < this->getMovementSpeed(terrainFactor); ++i) {
    doOneMove();
    if (this->isStill())
      break;
  }
  this->firstAttack = true;
}

void Unit::addMove(const Position &position) {
  if (std::find(movementsPositions.begin(), movementsPositions.end(), position)
      == movementsPositions.end())
    movementsPositions.push_back(position);
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

void Unit::receiveAttack(const Weapon &weapon) {
  this->damagesToReceive.push_back(weapon.damage);
}

void Unit::kill() {
  this->health = 0;
  this->movState.still();
}

void Unit::still() {
  this->movState.still();
  hunted = nullptr;
  capturable = nullptr;
  movementsPositions.clear();
  this->firstAttack = true;
  attackCounterActual = attackCounterBase;
}

bool Unit::isTimeToAttack() {
  this->firstAttack = false;
  if (attackCounterActual == 0) {
    attackCounterActual = attackCounterBase;
    return true;
  } else {
    attackCounterActual--;
  }
  return false;
}

bool Unit::hasDamagesToReceive() const {
  return !damagesToReceive.empty();
}

bool Unit::isInRange(Attackable *other) const {
  return this->currentPosition.euclideanDistance(other->getAttackPosition(
      currentPosition)) < range;
}

bool Unit::attackedInRange() const {
  Position huntedPos = hunted->getAttackPosition(currentPosition);
  unsigned long distance = currentPosition.euclideanDistance(huntedPos);
  bool b = distance < range;
  return b;
}

bool Unit::isAttacking() const {
  return this->movState.isHunting() || this->movState.isAutoAttacking();
}

bool Unit::isCapturing() const {
  return this->movState.isCapturing();
}

bool Unit::isStill() const {
  return this->movState.isStill();
}

bool Unit::isAlive() const {
  return health > 0;
}

bool Unit::canAttack(Attackable *attackable) const {
  return this->team.isEnemy(attackable->getOwner()->getID());
}

bool Unit::isMoving() const {
  return movState.isMoving();
}

bool Unit::isFirstAttack() const {
  return firstAttack;
}
bool Unit::isAutoAttacking() const {
  return movState.isAutoAttacking();
}

Position Unit::getCenterPosition() const {
  return this->currentPosition;
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

Attackable *Unit::getHunted() {
  return hunted;
}

UnitID Unit::getId() const {
  return this->id;
}

Bullet Unit::createBullet() {
  return Bullet(weapon, this->currentPosition, hunted);
}

Position Unit::getAttackPosition(const Position &attacker) const {
  return currentPosition;
}
Player *Unit::getOwner() {
  return owner;
}
Team Unit::getOwnerTeam() {
  return team;
}
Capturable *Unit::getCapturable() {
  return capturable;
}

void Unit::doOneMove() {
  currentPosition.move(movementsPositions.front());
  if (currentPosition == movementsPositions.front()) {
    movementsPositions.erase(movementsPositions.begin());
  }
  if (movementsPositions.empty() && this->isMoving()) {
    this->still();
  }
}

Unit::~Unit() {}
