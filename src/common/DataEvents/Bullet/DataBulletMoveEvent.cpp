#include "DataBulletMoveEvent.h"
DataBulletMoveEvent::DataBulletMoveEvent() {}
DataBulletMoveEvent::DataBulletMoveEvent(const BulletID &id,
                                         const Position &posTo)
    : id(id), posTo(posTo) {}
