#include <client/view/Sprite.h>
#include "BulletHitEvent.h"

BulletHitEvent::BulletHitEvent(const BulletID &id,
                               const Position &pos,
                               const WeaponType &type)
    : id(id), pos(pos), weapon(type) {}

void BulletHitEvent::process() {
  if (weapon != BULLET) {
    view->removeBulletVista(id);
    Sprite *bulletExplosion = VistasFactory::getBulletHitVista(weapon, pos);
    view->addExplosionVista(bulletExplosion);
  }
}
