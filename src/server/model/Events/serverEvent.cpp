#include "serverEvent.h"

serverEvent::serverEvent(const EventType &type) : type(type) {}

EventType serverEvent::getType() const{
  return type;
}
