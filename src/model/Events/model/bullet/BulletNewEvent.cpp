#include "BulletNewEvent.h"

BulletNewEvent::BulletNewEvent(const Bullet &bullet)
    : id(bullet.getId()),
      weapon(bullet.getWeapon()),
      from(bullet.getFrom()),
      to(bullet.getTo()) {}

void BulletNewEvent::process() {
  int rotation = from.getRoration(to);
  std::string rotation_s = std::to_string(rotation);
  ObjectMapaVista *bulletVista = VistasFactory::getBulletVista(weapon.type, rotation_s, from);
  if (bulletVista != nullptr) {
//    bulletVista->setPos(from);
    view->addBulletVista(this->id, bulletVista);
  }
}
