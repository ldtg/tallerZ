#ifndef TALLERZ_EVENTHANDLER_H
#define TALLERZ_EVENTHANDLER_H

class Event;

#include "client/model/Model.h"
#include "client/view/View.h"
#include "Event.h"

class EventHandler {
 private:
  Model *model;
  View *view;
  std::queue<Event*> eventQueue;
  std::vector<std::vector<Event*>> steps;

 public:
//  EventHandler();
  void setModel(Model *model);
  void setView(View *view);

  void add(Event *event);
  Event *get();

  void addStep(Event *stepEvent, int stepNumber);
  std::vector<Event*> getSteps(int stepNumber);
  unsigned long amountSteps();
  void clearSteps();

  bool empty();
};

#endif //TALLERZ_EVENTHANDLER_H
