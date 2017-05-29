#ifndef TALLERZ_OBJECTMAPAVISTA_H
#define TALLERZ_OBJECTMAPAVISTA_H

#include <model/Position.h>
#include "SDL2/SDL.h"

class ObjectMapaVista {
 protected:
  int width;
  int height;
  int x;
  int y;
  int rotation;
  bool _doCycle;
//  Position posTo;

 public:
  int getWidth() const;
  int getHeight() const;

  void setPos(Position pos);
  Position getPos() const;
  void setRotation(int rotation);
  int getRotation();
  bool doCycle() const;
//  void setPosTo(Position &pos);
//  bool isMoving();

  virtual void set_texture(SDL_Renderer *render);
  virtual void draw(SDL_Renderer *render) = 0;
};

#endif //TALLERZ_OBJECTMAPAVISTA_H
