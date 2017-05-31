#include "Controller.h"
#include "Quit.h"
#include "MouseButtonLeft.h"
#include "iostream"

Controller::Controller(EventHandler &eventHandler)
    : eventHandler(eventHandler) {}

void Controller::handle(SDL_Event *e) {
  Handler *h = HandlerFactory::get(e);
  if (h != nullptr)
    h->handle(e, eventHandler);

//  delete h;
}
