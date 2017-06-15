#ifndef TALLERZ_CLIENTE_VIEWPOSITION_H
#define TALLERZ_CLIENTE_VIEWPOSITION_H

#include <common/Map/Position.h>
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
  int getRoration(const ViewPosition &target) const;
};

#endif //TALLERZ_CLIENTE_VIEWPOSITION_H
