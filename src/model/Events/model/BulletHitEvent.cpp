#include <view/Sprite.h>
#include "BulletHitEvent.h"

BulletHitEvent::BulletHitEvent(const Bullet &bullet)
    : id(bullet.getId()), pos(bullet.getTo()), weapon(bullet.getWeapon()) {}

void BulletHitEvent::process() {
  if (weapon.type != BULLET) {
    view->removeBulletVista(id);
    ObjectMapaVista *bulletExplosion = new Sprite("../src/view/images/bullet/side_explosion_n", 7, 1);
    view->addExplosionVista(bulletExplosion, pos);
  }
}
