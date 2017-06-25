#ifndef TALLERZ_CLIENTE_EXPLOSIONVIEW_H
#define TALLERZ_CLIENTE_EXPLOSIONVIEW_H

#include <SDL_render.h>
#include "client/view/Camera.h"

class ExplosionView {
 public:
  virtual bool doCycle() const = 0;
  virtual void draw(SDL_Renderer *render, Camera &camera) = 0;
  virtual ~ExplosionView(){};
};

#endif //TALLERZ_CLIENTE_EXPLOSIONVIEW_H
