#ifndef TALLERZ_CAMERA_H
#define TALLERZ_CAMERA_H

#include <common/Map/Position.h>
struct Camera {
 public:
  int x;
  int y;
  int w;
  int h;
  int dirX;
  int dirY;
  int vel;
  int gap;
  Camera(int w, int h);
  void move(int x, int y);
  bool inLimits(int x, int y, int mapWidht, int mapHeight);
};

#endif //TALLERZ_CAMERA_H
