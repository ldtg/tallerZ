#include "dataBulletMoveEvent.h"
dataBulletMoveEvent::dataBulletMoveEvent() {}
dataBulletMoveEvent::dataBulletMoveEvent(const BulletID &id,
                                         const Position &posTo)
    : id(id), posTo(posTo) {}
