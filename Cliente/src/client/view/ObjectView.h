#ifndef TALLERZ_OBJECTMAPAVISTA_H
#define TALLERZ_OBJECTMAPAVISTA_H

#include <common/Map/Position.h>
#include "SDL2/SDL.h"
#include "Camera.h"
#include "ViewPosition.h"

/**
 * @class: ObjectView
 * Clase abstracta que representan las imágenes del juego, tanto animaciones
 * como imágenes fijas.
 */
class ObjectView {
 protected:
  int width;
  int height;
  float x;
  float y;
  int rotationDraw;
  double rotation;
  SDL_Point *pointRot;

  ObjectView();

 public:
  virtual ~ObjectView() {};

  int getWidth() const;
  int getHeight() const;

  void setPos(ViewPosition pos);
  void setPos(Position pos);

  Position getPos() const;
  ViewPosition getViewPos() const;

  void setDrawRotation(int rotation);
  int getDrawRotation() const;

  virtual void setRotation(double rotation);
  double getRotation() const;

  void setPointRotation(SDL_Point *pointRot);

  virtual void scale(float scaleW, float scaleH) = 0;
  virtual void set_texture(SDL_Renderer *render) = 0;
  /**
   * Este método es llamado a la hora de mostrar las imágenes.
   * @param render render sobre el cual se dibujaran todas las imagenes.
   * @param camera solo se dibujaran las imagenes que esten dentro de la camara.
   */
  virtual void draw(SDL_Renderer *render, Camera &camera) = 0;
};

#endif //TALLERZ_OBJECTMAPAVISTA_H
