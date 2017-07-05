#include "DataBulletHitEvent.h"
DataBulletHitEvent::DataBulletHitEvent() {}
DataBulletHitEvent::DataBulletHitEvent(const BulletID &id,
                                       const Position &pos,
                                       WeaponType weapon)
    : id(id), pos(pos), weapon(weapon) {}
