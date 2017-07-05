#include "Bullet.h"

Bullet::Bullet(const Weapon &weapon, const Position &current,
               Attackable *target)
    : id(), weapon(weapon), currentPosition(current), target(target) {
  if (weapon.speed == 0)
    currentPosition = target->getAttackPosition(currentPosition);
}

void Bullet::move() {
  for (unsigned short i = 0; i < this->weapon.speed; ++i) {
    currentPosition.move(target->getAttackPosition(currentPosition));
  }
}

void Bullet::doHit() {
  target->receiveAttack(weapon);
}

BulletID Bullet::getId() const {
  return this->id;
}

Weapon Bullet::getWeapon() const {
  return this->weapon;
}

Position Bullet::getFrom() const {
  return currentPosition;
}

Position Bullet::getTo() const {
  return target->getAttackPosition(currentPosition);
}

BulletState Bullet::getState() const {
  return BulletState(weapon.type, currentPosition);
}

bool Bullet::didHit() const {
  return weapon.speed == 0
      || currentPosition == target->getAttackPosition(currentPosition);
}

Bullet::~Bullet() {}
