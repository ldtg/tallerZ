#ifndef TALLERZ_EVENTHANDLER_H
#define TALLERZ_EVENTHANDLER_H

class Event;

#include "../Model.h"
#include "../../view/View.h"
#include "../Events/Event.h"

class EventHandler {
 private:
  Model *model;
  View *view;
  std::queue<Event*> eventQueue;

 public:
//  EventHandler();
  void setModel(Model *model);
  void setView(View *view);
  void add(Event *event);
  Event *get();
  bool empty();
};

#endif //TALLERZ_EVENTHANDLER_H
