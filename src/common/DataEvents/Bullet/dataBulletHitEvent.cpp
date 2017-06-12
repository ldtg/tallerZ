#include "dataBulletHitEvent.h"
dataBulletHitEvent::dataBulletHitEvent() {}
dataBulletHitEvent::dataBulletHitEvent(const BulletID &id,
                                       const Position &pos,
                                       WeaponType weapon)
    : id(id), pos(pos), weapon(weapon) {}
