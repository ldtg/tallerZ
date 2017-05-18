#ifndef TALLERZ_EVENT_H
#define TALLERZ_EVENT_H

#include "Map.h"
class Event {
virtual void process(Map &map) const = 0;
};

#endif //TALLERZ_EVENT_H
