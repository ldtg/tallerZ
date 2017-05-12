#include "UnitState.h"
void UnitState::moving() {
  this->movementState = MOVING;
}
void UnitState::still() {
  this->movementState = STILL;
}
void UnitState::receiveDamage(unsigned short damage) {
  if(this->health > damage)
    this->health -= damage;
  else
    this->health = 0;
}
bool UnitState::isAlive() {
  return this->health != 0;
}
void UnitState::hunting(Attackable *hunted) {
  this->movementState = HUNTING;
  this->hunted = hunted;
}
bool UnitState::isHunting() const{
  return this->movementState == HUNTING;
}
Attackable* UnitState::getHunted() {
  return hunted;
}
bool UnitState::isMoving() const{
  return this->movementState == MOVING;
}
void UnitState::capturing() {
  this->movementState = CAPTURING;
}
bool UnitState::isStill() const {
  return this->movementState == STILL;
}
bool UnitState::isCapturing() const{
  return this->movementState == CAPTURING;
}
