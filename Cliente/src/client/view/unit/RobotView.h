#ifndef TALLERZ_CLIENTE_ROBOTVIEW_H
#define TALLERZ_CLIENTE_ROBOTVIEW_H

#include "client/view/unit/UnitView.h"
class RobotView : public UnitView {
 public:
  RobotView(const UnitType &type, const std::string &color,
            const Position &pos, std::string &action,
            const std::string &rotation);
  void walk(int rotation, const Position &posTo);
  void still();
  void fire(const Position &huntedPos);
  void update();
};

#endif //TALLERZ_CLIENTE_ROBOTVIEW_H
