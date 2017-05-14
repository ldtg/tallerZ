#include "Unit.h"
Unit::Unit(Position current, UnitType type, WeaponType wtype) : currentPosition(
    current), state(type), weapon(wtype), id(type) {
}

Position Unit::getCurrentPosition() const {
  return this->currentPosition;
}
void Unit::move(std::queue<Movement> moves) {
  this->movements = moves;
  this->state.moving();
}

void Unit::attack(Attackable *other) {
  this->state.hunting(other);
  if (other->isAlive()) {
    other->receiveAttack(this->weapon.getDamage());
  } else {
    this->state.still();
    //clear moves
    while (!movements.empty()) movements.pop();
  }
}
bool Unit::isInRange(Attackable *other) {
  return this->currentPosition.euclideanDistance(other->getCurrentPosition())
      < range;
}
void Unit::receiveAttack(unsigned short damage) {
  this->damagesReceives.push_back(damage);
}
void Unit::hunt(std::queue<Movement> moves, Attackable *other) {
  this->movements = moves;
  this->state.hunting(other);
}
Movement Unit::nextMove() const {
  if (!movements.empty())
    return movements.back();
  else
    return Movement::STAY;
}
void Unit::receiveDamages() {
  for (unsigned short damage: damagesReceives) {
    this->state.receiveDamage(damage);
  }
}
void Unit::doMove() {
  currentPosition = currentPosition.move(movements.front());
  movements.pop();
  if (movements.empty())
    this->state.still();
}
bool Unit::attackedInRange() {
  return
      this->currentPosition.euclideanDistance(state.getHunted()->getCurrentPosition())
          < range;
}
bool Unit::isHunting() {
  return this->state.isHunting();
}
void Unit::doAttack() {
  if (state.getHunted()->isAlive()) {
    state.getHunted()->receiveAttack(this->weapon.getDamage());
  } else {
    this->state.still();
    //clear moves
    while (!movements.empty()) movements.pop();
  }
}
Attackable *Unit::getHunted() {
  return this->state.getHunted();
}
void Unit::addMove(Movement movement) {
  this->movements.push(movement);
}
Weapon Unit::getWeapon() {
  return this->weapon;
}
void Unit::capture(std::queue<Movement> moves) {
  this->movements = moves;
  this->state.capturing();
}
bool Unit::isCapturing() const {
  return this->state.isCapturing();
}
bool Unit::isStill() const {
  return this->state.isStill();
}
UnitID Unit::getId() const {
  return this->id;
}
Position Unit::nextPosition() const {
  return this->currentPosition.move(this->nextMove());
}
UnitState Unit::getState() const {
  return state;
}
bool Unit::isAlive() const {
  return state.isAlive();
}
bool Unit::isMoving() const {
  return state.isMoving();
}
unsigned long Unit::getHealth() const{
  return state.getHealth();
}
