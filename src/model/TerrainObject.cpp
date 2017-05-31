#include "TerrainObject.h"
#include "Data.h"
Position TerrainObject::getAttackPosition(const Position &attacker) const {
  return centerPosition.getAttackPosition(attacker, size);
}
bool TerrainObject::isAlive() const {
  return health > 0;
}
bool TerrainObject::isMoving() const {
  return false;
}
Position TerrainObject::nextMovePosition() const {
  return centerPosition;
}
void TerrainObject::receiveAttack(const Weapon &weapon) {
  if (weapon.isExplosive) {
    damagesToReceive.push_back(weapon.damage);
  }
}
bool TerrainObject::hasDamagesToReceive() const {
  return !damagesToReceive.empty();
}
void TerrainObject::receiveDamages() {
  for (auto damage: damagesToReceive) {
    if (this->health > damage) {
      this->health -= damage;
    } else {
      this->health = 0;
      damagesToReceive.clear();
      passable = !(this->id.getType() == TerrainObjectType::BRIDGE);
      return;
    }
  }
  damagesToReceive.clear();
}
TerrainObjectID TerrainObject::getID() const {
  return id;
}
TerrainObjectState TerrainObject::getState() const {
  return TerrainObjectState(centerPosition, size, health, passable);
}
TerrainObject::TerrainObject(const TerrainObjectData &data,
                             const Position &centerPos, Player &owner)
    : id(data.type),
      centerPosition(centerPos),
      health(data.health),
      size(data.size),
      passable(data.passable), owner(owner) {

}
Player &TerrainObject::getOwner() {
  return owner;
}
