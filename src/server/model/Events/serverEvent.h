#ifndef TALLERZ_SERVEREVENT_H
#define TALLERZ_SERVEREVENT_H

#include <common/DataEvents/EventType.h>
#include <sstream>
class serverEvent {
 protected:
  EventType type;
  serverEvent(const EventType &type);
 public:
  EventType getType() const;
  virtual std::stringstream getDataToSend() const = 0;
};

#endif //TALLERZ_SERVEREVENT_H
