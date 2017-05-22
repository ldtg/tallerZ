#ifndef TALLERZ_QUITEVENT_H
#define TALLERZ_QUITEVENT_H

#include "Event.h"

class QuitEvent : public Event {
 public:
  QuitEvent(Model &model, View &view);
  void process();
};

#endif //TALLERZ_QUITEVENT_H
