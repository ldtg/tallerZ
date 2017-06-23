#include <client/view/Sprite.h>
#include <client/view/sounds/Sound.h>
#include <client/view/sounds/SoundsFactory.h>
#include "BulletHitEvent.h"

BulletHitEvent::BulletHitEvent(const BulletID &id,
                               const Position &pos,
                               const WeaponType &type)
    : id(id), pos(pos), weapon(type) {}

void BulletHitEvent::process() {
  view->removeBulletVista(id);
  ExplosionView *bulletExplosion = VistasFactory::getBulletHitVista(weapon, pos);
  view->addExplosionVista(bulletExplosion);

  model->getMap().removeBullet(id);

//  SoundPlayer &soundPlayer = view->getSoundPlayer();
//  Sound *sound = SoundsFactory::getBulletHitSound(weapon);
//  soundPlayer.add(sound);
}
