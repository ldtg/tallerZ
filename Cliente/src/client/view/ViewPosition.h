#ifndef TALLERZ_CLIENTE_VIEWPOSITION_H
#define TALLERZ_CLIENTE_VIEWPOSITION_H

#include <common/Map/Position.h>

/**
 * class ViewPosition
 * Representa el x,y de un objeto en la vista.
 */
class ViewPosition {
 private:
  float x;
  float y;

 public:
  ViewPosition(float x, float y);
  float getX() const;
  float getY() const;
  Position getPos() const;
  void add(ViewPosition other);
  /**
   * @param target posicion contra la que se calcula la rotación.
   * @return angulo multiplo de 45°. Se utiliza para saber la rotacion de
   * la imagen a mostrar.
   */
  int getDrawRoration(const ViewPosition &target) const;
  /**
   * @param target posicion contra la que se calcula la rotación.
   * @return ángulo entre ambas posiciones. Esta es utilizada a
   * la hora de dibujar las imágenes en la función SDL_RenderCopyEx().
   * La relacion entre el angulo devuelto con los angulos tradiconales es:
   * 0 -> 0
   * 90 -> -90
   * 180 -> -180/180
   * 270 -> 90
   */
  double getRotation(const ViewPosition &target) const;
};

#endif //TALLERZ_CLIENTE_VIEWPOSITION_H
