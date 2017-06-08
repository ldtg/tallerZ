#include "BulletNewEvent.h"
BulletNewEvent::BulletNewEvent(const BulletID &bullet,
                               const WeaponType &weaponType,
                               const Position &from,
                               const Position &to) :id(bullet), weapon(weaponType), from(from), to(to){

}

void BulletNewEvent::process() {
  int rotation = from.getRoration(to);
  std::string rotation_s = std::to_string(rotation);
  ObjectMapaVista *bulletVista = VistasFactory::getBulletVista(weapon, rotation_s, from);
  if (bulletVista != nullptr) {
    view->addBulletVista(this->id, bulletVista);
  }
}
