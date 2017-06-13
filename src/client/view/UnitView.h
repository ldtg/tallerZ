#ifndef TALLERZ_ROBOTVIEW_H
#define TALLERZ_ROBOTVIEW_H

#include <common/Types/UnitType.h>
#include <queue>
#include "Sprite.h"

class UnitView {
 private:
  Sprite *view;
  std::queue<Position> movements;
  UnitType type;
  std::string color;

 public:
  UnitView(UnitType type, std::string &color, Position pos,
           std::string &action, std::string &rotation);
  Position getPos() const;
  void addMove(const Position &pos);
  void update();
  Sprite* getView();
};

#endif //TALLERZ_ROBOTVIEW_H
