#ifndef TALLERZ_CLIENTE_BULLETVIEW_H
#define TALLERZ_CLIENTE_BULLETVIEW_H

#include <common/Types/WeaponType.h>
#include "client/view/ObjectViewMove.h"

class BulletView : public ObjectViewMove {
 private:
  WeaponType type;
 public:
  BulletView(const WeaponType &type, const Position &from, const Position &to);
  void walk(int rotation, const Position &posTo);
  void still();
  Sprite* getView();
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_BULLETVIEW_H
