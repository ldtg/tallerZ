#ifndef TALLERZ_OBJECTMAPAVISTA_H
#define TALLERZ_OBJECTMAPAVISTA_H

#include <common/Map/Position.h>
#include "SDL2/SDL.h"
#include "Camera.h"
#include "ViewPosition.h"

class ObjectMapaVista {
 protected:
  int width;
  int height;
  float x;
  float y;
  int rotation;
  ObjectMapaVista();

 public:
  virtual ~ObjectMapaVista() {};

  int getWidth() const;
  int getHeight() const;
  void setPos(ViewPosition pos);
  void setPos(Position pos);
  Position getPos() const;
  ViewPosition getViewPos() const;
  void setRotation(int rotation);
  int getRotation();

  virtual void scale(float scaleW, float scaleH) = 0;
  virtual void set_texture(SDL_Renderer *render) = 0;
  virtual void draw(SDL_Renderer *render, Camera &camera) = 0;
};

#endif //TALLERZ_OBJECTMAPAVISTA_H
