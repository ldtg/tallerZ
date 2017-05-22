#include "EventHandler.h"

EventHandler::EventHandler() {}

void EventHandler::add(Event *event) {
//  event->setModel(model);
//  event->setView(view);
  eventQueue.push(event);
}

Event* EventHandler::get() {
  Event *event_aux = eventQueue.back();
  eventQueue.pop();
  return event_aux;
}

bool EventHandler::empty() {
  return eventQueue.empty();
}
