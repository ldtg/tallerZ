#ifndef TALLERZ_CLIENTE_ROBOTVIEW_H
#define TALLERZ_CLIENTE_ROBOTVIEW_H

#include "UnitView.h"
class RobotView : public UnitView {
 public:
  RobotView(UnitType type, std::string &color, Position pos,
  std::string &action, std::string &rotation);
  void walk(int rotation, const Position &posTo);
  void still();
  void fire(const Position &huntedPos);
  void update();
};

#endif //TALLERZ_CLIENTE_ROBOTVIEW_H
