#include "BulletMoveEvent.h"

void BulletMoveEvent::process() {
  view->move(id, posTo);
}
BulletMoveEvent::BulletMoveEvent(const BulletID &id, const Position &to)
    : id(id), posTo(to) {
}
