#include <iostream>
#include "EventHandler.h"

//EventHandler::EventHandler(Model *model, View *view)
//    : model(model), view(view) {}

//EventHandler::EventHandler() : steps(1) {}

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


void EventHandler::addStep(Event *stepEvent, int stepNumber) {
  if (stepNumber >= steps.size())
    steps.resize(stepNumber+1);

  stepEvent->setModel(model);
  stepEvent->setView(view);
  steps[stepNumber].push_back(stepEvent);
}

std::vector<Event*> EventHandler::getSteps(int stepNumber) {
  return steps[stepNumber];
}

void EventHandler::clearSteps() {
  steps.clear();
}

unsigned long EventHandler::amountSteps() {
  return steps.size();
}


bool EventHandler::empty() {
  return eventQueue.empty();
}
