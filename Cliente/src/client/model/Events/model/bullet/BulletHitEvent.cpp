#include <client/view/Sprite.h>
#include "BulletHitEvent.h"

BulletHitEvent::BulletHitEvent(const BulletID &id,
                               const Position &pos,
                               const WeaponType &type)
    : id(id), pos(pos), weapon(type) {}

void BulletHitEvent::process() {
  view->removeBulletView(id);
  ExplosionView *bulletExplosion = ViewFactory::getBulletHitVista(weapon, pos);
  view->addExplosionView(bulletExplosion);

  model->getMap().removeBullet(id);
}
