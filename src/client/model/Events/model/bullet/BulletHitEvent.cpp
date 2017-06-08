#include <client/view/Sprite.h>
#include "BulletHitEvent.h"

void BulletHitEvent::process() {
  if (weapon != BULLET) {
    view->removeBulletVista(id);
    Sprite
        *bulletExplosion = VistasFactory::getBulletHitVista(weapon, pos);
    view->addExplosionVista(bulletExplosion);
  }
}
BulletHitEvent::BulletHitEvent(const BulletID &id, const WeaponType &type) : id(
    id), weapon(type) {

}
