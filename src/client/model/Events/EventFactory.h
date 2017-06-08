#ifndef TALLERZ_EVENTFACTORY_H
#define TALLERZ_EVENTFACTORY_H

#include <common/DataEvents/EventType.h>
#include "Event.h"
class EventFactory {
 public:
  static Event *createEvent(const EventType &type, std::stringstream &ss);

};

#endif //TALLERZ_EVENTFACTORY_H
