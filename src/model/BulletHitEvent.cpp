#include "BulletHitEvent.h"

BulletHitEvent::BulletHitEvent(const Bullet &bullet)
    : id(bullet.getId()), position(bullet.getTo()) {

}
void BulletHitEvent::process() {
}
