#include "Bullet.h"
Bullet::Bullet(const Weapon &weapon,
               const Position &current,
               Attackable *target)
    : id(), weapon(weapon), currentPosition(current), target(target) {
  if (weapon.speed == 0)
    currentPosition = target->getCurrentPosition();
}
bool Bullet::didHit() const {
  return currentPosition == target->getCurrentPosition();
}
void Bullet::move() {
  for (unsigned short i = 0; i < this->weapon.speed; ++i) {
    currentPosition.move(target->getCurrentPosition());
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
  return target->getCurrentPosition();
}
BulletState Bullet::getState() const {
  return BulletState(weapon, currentPosition);
}
