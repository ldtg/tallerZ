#include "RobotView.h"

RobotView::RobotView(const UnitType &type, const std::string &color,
                     const Position &pos, std::string &action,
                     const std::string &rotation)
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

void RobotView::update() {
  ObjectViewMove::update();

  // Se cambia a otro tipo de look_around.
  if ( (state.isStill() || state.isCreating()) && view->doCycle() ) {
    still();
  }
}
