#ifndef TALLERZ_CLIENTE_BULLETVIEW_H
#define TALLERZ_CLIENTE_BULLETVIEW_H

#include <common/Types/WeaponType.h>
#include "ObjectViewMove.h"

class BulletView : public ObjectViewMove {
 private:
  WeaponType type;
 public:
  BulletView(WeaponType type, std::string &rotation, Position pos);
  void walk(int rotation, const Position &posTo);
  Sprite* getView();
};

#endif //TALLERZ_CLIENTE_BULLETVIEW_H
