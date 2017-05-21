#include "Controller.h"
#include "Quit.h"
#include "Mouse.h"

Controller::Controller(Vista &vista) : vista(vista) {}

void Controller::handle(SDL_Event *e) {
//  _quit.handle(e);
//  for (Handler *handler : handlers)
//    handler->handle(e);
  HandlerFactory::get(e->type, vista)->handle(e);
}
