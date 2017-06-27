#include "BulletNewEvent.h"

BulletNewEvent::BulletNewEvent(const BulletID &bullet,
                               const WeaponType &weaponType,
                               const Position &from,
                               const Position &to)
    : id(bullet), weapon(weaponType), from(from), to(to){}

void BulletNewEvent::process() {
  BulletView *bulletVista = new BulletView(weapon, from, to);
  view->addBulletView(this->id, bulletVista);

  BulletState state(weapon, from);
  model->getMap().addBullet(id, state);
}
