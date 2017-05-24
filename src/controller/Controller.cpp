#include "Controller.h"
#include "Quit.h"
#include "Mouse.h"
#include "iostream"

Controller::Controller(EventHandler &eventHandler)
    : eventHandler(eventHandler) {}

void Controller::handle(SDL_Event *e) {
  HandlerFactory::get(e->type)->handle(e, eventHandler);
}
