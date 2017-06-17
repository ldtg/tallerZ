#ifndef TALLERZ_CAMERA_H
#define TALLERZ_CAMERA_H

#include <common/Map/Position.h>
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
  void move(int x, int y);
  bool inLimits(int x, int y);
};

#endif //TALLERZ_CAMERA_H
