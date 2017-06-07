#include "BulletMoveEvent.h"

BulletMoveEvent::BulletMoveEvent(const Bullet &bullet)
    : id(bullet.getId()), posTo(bullet.getFrom()) {}

void BulletMoveEvent::process() {
  view->move(id, posTo);
}
