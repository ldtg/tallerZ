#ifndef TALLERZ_CLIENTE_OBJECTVIEWMOVE_H
#define TALLERZ_CLIENTE_OBJECTVIEWMOVE_H

#include <queue>
#include "ViewPosition.h"
#include "ObjectMapaVista.h"
#include "Sprite.h"

class ObjectViewMove {
 protected:
  Sprite *view;
  std::queue<ViewPosition> movements;
  bool lastMove;
  ObjectViewMove(Sprite *view);

 public:
  Position getPos() const;
  ViewPosition getViewPos() const;
  void addMove(const ViewPosition &pos);
  void setLastMove();
  virtual void walk(int rotation, const Position &posTo) = 0;
  virtual void still() = 0;
  void update();
};

#endif //TALLERZ_CLIENTE_OBJECTVIEWMOVE_H
