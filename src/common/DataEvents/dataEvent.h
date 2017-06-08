#ifndef TALLERZ_SERVEREVENT_H
#define TALLERZ_SERVEREVENT_H

#include <iosfwd>
class dataEvent {
 public:
  virtual std::stringstream getStream() const=0;
};

#endif //TALLERZ_SERVEREVENT_H
