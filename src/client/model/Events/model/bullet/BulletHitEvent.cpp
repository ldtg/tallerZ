#include <client/view/Sprite.h>
#include "BulletHitEvent.h"

BulletHitEvent::BulletHitEvent(const BulletID &id,
                               const Position &pos,
                               const WeaponType &type)
    : id(id), pos(pos), weapon(type) {}

void BulletHitEvent::process() {
//  std::cout << "HIT HIT HIT HIT" << std::endl;
//  std::cout << id.getID() << std::endl;

  view->removeBulletVista(id);
  if (weapon != BULLET) {
    Sprite *bulletExplosion = VistasFactory::getBulletHitVista(weapon, pos);
    view->addExplosionVista(bulletExplosion);
  }
}
