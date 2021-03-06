#include "TerrainObject.h"
TerrainObject::TerrainObject(const TerrainObjectData &data,
                             const Position &centerPos, Player *owner)
    : id(data.type),
      centerPosition(centerPos),
      health(data.health),
      size(data.size),
      passable(data.passable), owner(owner) {}

Position TerrainObject::getAttackPosition(const Position &attacker) const {
  return centerPosition.getAttackPosition(attacker,
                                          (unsigned short) (size + 1));
}

void TerrainObject::receiveAttack(const Weapon &weapon) {
  if (isAlive() && weapon.isExplosive)
    damagesToReceive.push_back(weapon.damage);
}

void TerrainObject::receiveDamages() {
  for (auto damage: damagesToReceive) {
    if (this->health > damage) {
      this->health -= damage;
    } else {
      this->health = 0;
      damagesToReceive.clear();
      passable = !(this->id.getType() == TerrainObjectType::_ASPHALTEDBRIDGE
          || this->id.getType() == TerrainObjectType::_WOODENBRIDGE);
      return;
    }
  }
  damagesToReceive.clear();
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

bool TerrainObject::hasDamagesToReceive() const {
  return !damagesToReceive.empty();
}

TerrainObjectID TerrainObject::getID() const {
  return id;
}

TerrainObjectState TerrainObject::getState() const {
  return TerrainObjectState(centerPosition, size, health, passable);
}

Player *TerrainObject::getOwner() {
  return owner;
}

Position TerrainObject::getCenterPosition() const {
  return centerPosition;
}
TerrainObject::~TerrainObject() {}
