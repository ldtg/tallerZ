#include "HandlerFactory.h"
#include "Quit.h"
#include "Mouse.h"
#include "NullHandler.h"

Handler* HandlerFactory::get(unsigned int type, Vista &vista) {
  switch (type) {
    case SDL_QUIT:
      return new Quit(vista);
    case SDL_MOUSEBUTTONUP:
      return new Mouse(vista);
    default:
      return new NullHandler(vista);
  }
}
