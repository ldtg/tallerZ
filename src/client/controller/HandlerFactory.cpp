#include <iostream>
#include <client/model/Events/view/CameraMove.h>
#include "HandlerFactory.h"
#include "Quit.h"
#include "MouseButtonLeft.h"
#include "NullHandler.h"
#include "MouseButtonRight.h"
#include "MouseMotion.h"
#include "MouseState.h"

Handler *HandlerFactory::get(SDL_Event *e) {
//    if (e->type == SDL_QUIT) {
  if (e->type == SDL_KEYDOWN) {
    switch (e->key.keysym.sym) {
      case SDLK_ESCAPE:return new Quit();
        break;
      default:return nullptr;
    }
  } else if (e->type == SDL_MOUSEBUTTONDOWN) {
    if (e->button.button == SDL_BUTTON_LEFT)
      return new MouseButtonLeft();
    else if (e->button.button == SDL_BUTTON_RIGHT)
      return new MouseButtonRight();
  } else {
    return nullptr;
  }
  return nullptr;
}
