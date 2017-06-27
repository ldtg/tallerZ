#ifndef TALLERZ_CAMERA_H
#define TALLERZ_CAMERA_H

#include <common/Map/Position.h>

/**
 * @class Camera
 * Camara del juego, enfoca la parte del mapa que indique el jugador.
 * Perimite que se dibuje solo lo que es enfocado por ella, ahorrando tiempo
 * cada vez que se dibuja.
 */
struct Camera {
 public:
  int x;
  int y;
  int w;
  int h;
  int mapWidth;
  int mapHeight;
  int dirX;
  int dirY;
  int vel;
  int gap;
  Camera(int w, int h, int mapWidth, int mapHeight, const Position &initial);
  /**
   * Se mueve en la dirección que corresponda de acuerdo a los
   * valores de x,y pasados por parámetro.
   * @param x del puntero del mouse
   * @param y del puntero del mouse
   */
  void move(int x, int y);
  /**
   * @param x del puntero del mouse
   * @param y del puntero del mouse
   * @return true si el x, y se encuentra dentro del area de la camara.
   */
  bool inLimits(int x, int y);
};

#endif //TALLERZ_CAMERA_H
