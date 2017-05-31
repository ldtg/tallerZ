#include "HandlerFactory.h"
#include "Quit.h"
#include "MouseButtonLeft.h"
#include "NullHandler.h"
#include "MouseButtonRight.h"

Handler* HandlerFactory::get(SDL_Event *e) {
    if (e->type == SDL_QUIT) {
      return new Quit();
    }
    else if (e->type == SDL_MOUSEBUTTONDOWN) {
      if (e->button.button == SDL_BUTTON_LEFT)
        return new MouseButtonLeft();
      else if (e->button.button == SDL_BUTTON_RIGHT)
        return new MouseButtonRight();
    }
    else {
//      return new NullHandler();
      return nullptr;
    }
}
