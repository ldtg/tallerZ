#include "BulletNewEvent.h"

BulletNewEvent::BulletNewEvent(const BulletID &bullet,
                               const WeaponType &weaponType,
                               const Position &from,
                               const Position &to)
    : id(bullet), weapon(weaponType), from(from), to(to){}

void BulletNewEvent::process() {
//  std::cout << "NEW NEW NEW NEW" << std::endl;
//  std::cout << id.getID() << std::endl;

  int rotation = from.getRoration(to);
  std::string rotation_s = std::to_string(rotation);
//  ObjectMapaVista *bulletVista = VistasFactory::getBulletVista(weapon, rotation_s, from);
  BulletView *bulletVista = new BulletView(weapon, rotation_s, from);
  view->addBulletVista(this->id, bulletVista);
}
