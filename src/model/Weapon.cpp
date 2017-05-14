#include "Weapon.h"
unsigned short Weapon::getDamage() {
  return damage;
}
Weapon::Weapon(WeaponType type) : type(type){
  damage = 10;
}
