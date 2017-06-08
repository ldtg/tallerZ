#ifndef TALLERZ_CAMERA_H
#define TALLERZ_CAMERA_H

#include <server/model/Position.h>
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
//  Position translateToViewPos(Position &pos);
//  Position translateToModelPos(Position &pos);
};

#endif //TALLERZ_CAMERA_H
