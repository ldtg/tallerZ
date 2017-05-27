#include "BulletNewEvent.h"
BulletNewEvent::BulletNewEvent(const Bullet &bullet)
    : id(bullet.getId()),
      weapon(bullet.getWeapon()),
      from(bullet.getFrom()), to(bullet.getTo()) {}
void BulletNewEvent::process() {
}
