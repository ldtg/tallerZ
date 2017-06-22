#ifndef TALLERZ_SERVEREVENT_H
#define TALLERZ_SERVEREVENT_H

#include <common/DataEvents/EventType.h>
#include <sstream>

class ServerEvent {
 protected:
  EventType type;
  ServerEvent(const EventType &type);
 public:
  EventType getType() const;
  //es en todos los ev igual pero si se declara aca le falta el data
  virtual std::stringstream getDataToSend() const = 0;
  virtual ~ServerEvent(){};
};

#endif //TALLERZ_SERVEREVENT_H
