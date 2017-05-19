#include "Unit.h"
#include <algorithm>

Position Unit::getCurrentPosition() const {
  return this->currentPosition;
}
void Unit::move(std::vector<Position> movementsPositions) {
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
    movementsPositions.clear();
  }
}
bool Unit::isInRange(Attackable *other) {
  return this->currentPosition.euclideanDistance(other->getCurrentPosition())
      < range;
}
void Unit::receiveAttack(Weapon weapon) {
  this->damagesToReceive.push_back(weapon.damage);
}
void Unit::hunt(std::vector<Position> movementsPositions, Attackable *other) {
  this->movementsPositions = movementsPositions;
  this->movState.hunting();
  this->hunted = other;
}
Position Unit::nextMovePosition() const {
  if (!movementsPositions.empty())
    return movementsPositions.front();
  else
    return currentPosition;
}
void Unit::receiveDamages() {
  for (unsigned short damage: damagesToReceive) {
    if (health >= damage)
      this->health -= damage;
    else
      this->health = 0;
  }
  damagesToReceive.clear();
}
void Unit::doOneMove() {
  auto aux = movementsPositions.front();
  currentPosition.move(movementsPositions.front());
  if (currentPosition == movementsPositions.front()) {
    movementsPositions.erase(movementsPositions.begin());
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
    hunted = nullptr;
    movementsPositions.clear();
  }
}
Attackable *Unit::getHunted() {
  return hunted;
}

Weapon Unit::getWeapon() {
  return this->weapon;
}
void Unit::capture(std::vector<Position> movementsPositions) {
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
  return UnitState(health, weapon, currentPosition);
}
void Unit::addMove(const Position &position) {
  if (std::find(movementsPositions.begin(), movementsPositions.end(), position)
      == movementsPositions.end())
    movementsPositions.push_back(position);
}
bool Unit::hasDamagesToReceive() const {
  return !damagesToReceive.empty();
}

