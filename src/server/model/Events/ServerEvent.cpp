#include "ServerEvent.h"

ServerEvent::ServerEvent(const EventType &type) : type(type) {}

EventType ServerEvent::getType() const{
  return type;
}
