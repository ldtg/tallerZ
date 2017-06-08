#include "serverUMoveEvent.h"
serverUMoveEvent::serverUMoveEvent(const UnitID &id, const Position &pos)
    : serverEvent(U_MOVE), data(id, pos) {}
std::stringstream serverUMoveEvent::getDataToSend() const {
  return data.getStream();
}
