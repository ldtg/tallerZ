#include "Unit.h"
#include <algorithm>

Position Unit::getCurrentPosition() const {
  return this->currentPosition;
}
void Unit::move(std::queue<Position> movementsPositions) {
  this->movementsPositions = movementsPositions;
  this->movState.moving();
}

void Unit::attack(Attackable *other) {
  this->movState.hunting();
  this->hunted = other;
  if (other->isAlive()) {
    other->receiveAttack(this->weapon);
  } else {
    this->movState.still();
    //clear moves
    while (!movementsPositions.empty()) movementsPositions.pop();
  }
}
bool Unit::isInRange(Attackable *other) {
  return this->currentPosition.euclideanDistance(other->getCurrentPosition())
      < range;
}
void Unit::receiveAttack(Weapon weapon) {
  this->damagesReceives.push_back(weapon.damage);
}
void Unit::hunt(std::queue<Position> movementsPositions, Attackable *other) {
  this->movementsPositions = movementsPositions;
  this->movState.hunting();
  this->hunted = other;
}
Position Unit::nextMovePosition() const {
  if (!movementsPositions.empty())
    return movementsPositions.back();
  else
    return currentPosition;
}
void Unit::receiveDamages() {
  for (unsigned short damage: damagesReceives) {
    if (health >= damage)
      this->health -= damage;
    else
      this->health = 0;
  }
}
void Unit::doOneMove() {
  currentPosition.move(movementsPositions.front());
  if (currentPosition == movementsPositions.front()) {
    movementsPositions.pop();

  }
  if (movementsPositions.empty())
    this->movState.still();
}
bool Unit::attackedInRange() {
  return currentPosition.euclideanDistance(hunted->getCurrentPosition())
      < range;
}
bool Unit::isHunting() {
  return this->movState.isHunting();
}
void Unit::doAttack() {
  if (hunted->isAlive()) {
    hunted->receiveAttack(this->weapon);
  } else {
    this->movState.still();
    //clear moves
    while (!movementsPositions.empty()) movementsPositions.pop();
  }
}
Attackable *Unit::getHunted() {
  return hunted;
}

Weapon Unit::getWeapon() {
  return this->weapon;
}
void Unit::capture(std::queue<Position> movementsPositions) {
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
void Unit::doMoveWithSpeed(float terrainFactor) {
  for (int i = 0; i < this->getMovementSpeed(terrainFactor); ++i) {
    doOneMove();
  }
}
Unit::Unit(Position current, UnitData data)
    : currentPosition(current),
      weapon(data.weapon),
      baseSpeed(data.speed),
      range(data.range),
      health(data.health),
      id(data.type),
      movState(),
      hunted(nullptr) {

}
UnitState Unit::getUnitState() {
  return UnitState(health, weapon);
}

