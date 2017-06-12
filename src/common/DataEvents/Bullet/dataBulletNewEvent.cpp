#include "dataBulletNewEvent.h"
dataBulletNewEvent::dataBulletNewEvent(const BulletID &id,
                                       WeaponType weapon,
                                       const Position &from,
                                       const Position &to)
    : id(id), weapon(weapon), from(from), to(to) {}
