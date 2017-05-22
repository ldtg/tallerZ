#include "Controller.h"
#include "Quit.h"
#include "Mouse.h"

Controller::Controller(EventHandler &eventHandler, Model &model, View &view)
    : eventHandler(eventHandler), model(model), view(view) {}

void Controller::handle(SDL_Event *e) {
//  _quit.handle(e);
//  for (Handler *handler : handlers)
//    handler->handle(e);
  HandlerFactory::get(e->type)->handle(e, eventHandler, model, view);
}
