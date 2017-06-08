#include <client/view/Sprite.h>
#include "BulletHitEvent.h"

BulletHitEvent::BulletHitEvent(const Bullet &bullet)
    : id(bullet.getId()), pos(bullet.getTo()), weapon(bullet.getWeapon()) {}

void BulletHitEvent::process() {
  if (weapon.type != BULLET) {
    view->removeBulletVista(id);
    Sprite *bulletExplosion = VistasFactory::getBulletHitVista(weapon.type, pos);
    view->addExplosionVista(bulletExplosion);
  }
}
