#include <client/view/sounds/SoundsFactory.h>
#include "BulletNewEvent.h"

BulletNewEvent::BulletNewEvent(const BulletID &bullet,
                               const WeaponType &weaponType,
                               const Position &from,
                               const Position &to)
    : id(bullet), weapon(weaponType), from(from), to(to){}

void BulletNewEvent::process() {
  int rotation = from.getRoration(to);
  std::string rotation_s = std::to_string(rotation);
  BulletView *bulletVista = new BulletView(weapon, rotation_s, from);
  view->addBulletVista(this->id, bulletVista);

  SoundPlayer &soundPlayer = view->getSoundPlayer();
  Sound *sound = SoundsFactory::getBulletFireSound(weapon);
  soundPlayer.add(sound);
}
