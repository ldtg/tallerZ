#include "Build.h"
#include "Data.h"
Position Build::getCurrentPosition() const {
  return centerPosition;
}
PlayerID Build::getOwner() const {
  return owner.getID();
}
bool Build::isAlive() const {
  return health > 0;
}
bool Build::isMoving() const {
  return false;
}
Position Build::nextMovePosition() const {
  return centerPosition;
}
void Build::receiveAttack(const Weapon &weapon) {
  if (weapon.isExplosive)
    this->damagesToReceive.push_back(weapon.damage);
}
Position Build::getAttackPosition(const Position &attackerPosition) const {
  return centerPosition.getAttackPosition(attackerPosition, size);
}
void Build::tick() {
  if (ticksBeforeCreate > 0) {
    ticksBeforeCreate--;
  } else {
    ticksBeforeCreate = this->getSpeedRate();
    timeToBuild = true;
  }
}
bool Build::hasToBuild() {
  if (timeToBuild) {
    timeToBuild = false;
    return true;
  }
  return false;
}
unsigned short Build::getSpeedRate() const {
  unsigned long timeInSecs;
  double baseTaken = data.getData(actualUnitFab).factoryBaseTimeInSec
      / owner.getAmountOfTerritories();
  double rel = this->health / data.getData(this->id.getType()).health;
  double relsqrt = std::sqrt(1 - rel);
  timeInSecs = std::lround(baseTaken / relsqrt);

  return data.getTickAmount(timeInSecs);
}
bool Build::hasDamagesToReceive() const {
  return !damagesToReceive.empty();
}
void Build::receiveDamages() {
  for (auto damage: damagesToReceive) {
    if (this->health > damage) {
      this->health -= damage;
    } else {
      this->health = 0;
      owner.buildDestroyed(this->id.getType());
      return;
    }
  }
}
