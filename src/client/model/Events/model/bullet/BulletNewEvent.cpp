#include <client/view/sounds/SoundsFactory.h>
#include "BulletNewEvent.h"

BulletNewEvent::BulletNewEvent(const BulletID &bullet,
                               const WeaponType &weaponType,
                               const Position &from,
                               const Position &to)
    : id(bullet), weapon(weaponType), from(from), to(to){}

void BulletNewEvent::process() {
  BulletView *bulletVista = new BulletView(weapon, from, to);
  view->addBulletVista(this->id, bulletVista);

  BulletState state(weapon, from);
  model->getMap().addBullet(id, state);

//  SoundPlayer &soundPlayer = view->getSoundPlayer();
//  Sound *sound = SoundsFactory::getBulletFireSound(weapon);
//  soundPlayer.add(sound);
}
