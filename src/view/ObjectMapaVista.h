#ifndef TALLERZ_OBJECTMAPAVISTA_H
#define TALLERZ_OBJECTMAPAVISTA_H

#include <model/Position.h>
#include "SDL2/SDL.h"

class ObjectMapaVista {
 protected:
  int width;
  int height;
  long x;
  long y;
  int rotation;

 public:
  int getWidth() const;
  int getHeight() const;

  void setPos(Position pos);
  Position getPos() const;
  void setRotation(int rotation);
  int getRotation();

  virtual void set_texture(SDL_Renderer *render) = 0;
  virtual void draw(SDL_Renderer *render) = 0;
};

#endif //TALLERZ_OBJECTMAPAVISTA_H
