#include "EventHandler.h"

//EventHandler::EventHandler(Model *model, View *view)
//    : model(model), view(view) {}

void EventHandler::setModel(Model *model)  {
  this->model = model;
}

void EventHandler::setView(View *view) {
  this->view = view;
}

void EventHandler::add(Event *event) {
  event->setModel(model);
  event->setView(view);
  eventQueue.push(event);
}

Event* EventHandler::get() {
  Event *event_aux = eventQueue.front();
  eventQueue.pop();
  return event_aux;
}

bool EventHandler::empty() {
  return eventQueue.empty();
}
