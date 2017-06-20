#include "RobotView.h"

RobotView::RobotView(UnitType type, std::string &color,
                     Position pos, std::string &action,
                     std::string &rotation)
    : UnitView(type, color, pos, action, rotation) {}

void RobotView::walk(int rotation, const Position &posTo) {
  UnitView::walk(rotation, posTo);
  state.moving();
}

void RobotView::still() {
  UnitView::still();
  state.still();
}

void RobotView::fire(const Position &huntedPos) {
  UnitView::fire(huntedPos);
  state.attacking();
}
