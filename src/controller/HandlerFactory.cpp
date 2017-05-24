#include "HandlerFactory.h"
#include "Quit.h"
#include "Mouse.h"
#include "NullHandler.h"

Handler* HandlerFactory::get(unsigned int type) {
  switch (type) {
    case SDL_QUIT:
      return new Quit();
    case SDL_MOUSEBUTTONDOWN:
      return new Mouse();
    default:
      return new NullHandler();
  }
}
