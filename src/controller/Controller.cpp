#include "Controller.h"
#include "Quit.h"
#include "MouseButtonLeft.h"
#include "iostream"

Controller::Controller(EventHandler &eventHandler)
    : eventHandler(eventHandler) {}

void Controller::handle(SDL_Event *e) {
  HandlerFactory::get(e)->handle(e, eventHandler);
}
