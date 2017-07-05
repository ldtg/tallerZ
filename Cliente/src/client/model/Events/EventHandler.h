#ifndef TALLERZ_EVENTHANDLER_H
#define TALLERZ_EVENTHANDLER_H

class Event;

#include <queue>
#include "client/model/Model.h"
#include "client/view/View.h"
#include "Event.h"

class EventHandler {
 private:
  Model *model;
  View *view;
  std::queue<Event*> eventQueue;

 public:
  void setModel(Model *model);
  void setView(View *view);

  void add(Event *event);
  Event *get();
  bool empty();
};

#endif //TALLERZ_EVENTHANDLER_H
