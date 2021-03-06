#include "Controller.h"
#include "MouseState.h"
#include "HandlerFactory.h"

Controller::Controller(EventHandler &eventHandler)
    : eventHandler(eventHandler) {}

void Controller::handle(SDL_Event *e) {
  Handler *h = HandlerFactory::get(e);
  if (h != nullptr) {
    h->handle(e, eventHandler);
    delete h;
  }
}

void Controller::checkMouseState(SDL_Event *e) {
  MouseState mouseState;
  mouseState.handle(e, eventHandler);
}
