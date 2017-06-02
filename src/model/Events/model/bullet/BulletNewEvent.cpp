#include "BulletNewEvent.h"

BulletNewEvent::BulletNewEvent(const Bullet &bullet)
    : id(bullet.getId()),
      weapon(bullet.getWeapon()),
      from(bullet.getFrom()) {}
      //to(bullet.getTo()) {}

void BulletNewEvent::process() {

  if (weapon.type != BULLET) {
    ObjectMapaVista *bulletVista = view->getBulletVista(weapon.type);
    bulletVista->setPos(from);
    view->addBulletVista(this->id, bulletVista);
  }
}
