#ifndef TALLERZ_QUITEVENT_H
#define TALLERZ_QUITEVENT_H

#include "client/model/Events/Event.h"

class QuitEvent : public Event {
 public:
//  QuitEvent();
  void process();
};

#endif //TALLERZ_QUITEVENT_H
