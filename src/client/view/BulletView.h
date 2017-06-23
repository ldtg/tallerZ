#ifndef TALLERZ_CLIENTE_BULLETVIEW_H
#define TALLERZ_CLIENTE_BULLETVIEW_H

#include <common/Types/WeaponType.h>
#include "ObjectViewMove.h"

class BulletView : public ObjectViewMove {
 private:
  WeaponType type;
 public:
  BulletView(WeaponType type, Position from, Position to);
  void walk(int rotation, const Position &posTo);
  void still();
  Sprite* getView();
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_BULLETVIEW_H
