#include <iostream>
#include "VehicleView.h"
#include "VistasFactory.h"

VehicleView::VehicleView(UnitType type, std::string &color,
                         Position pos, std::string &action,
                         std::string &rotation)
    : UnitView(type, color, pos, action, rotation) {
  top = VistasFactory::getVehicleTopVista(type, color, pos);
}

void VehicleView::walk(int rotation, const Position &posTo) {
  UnitView::walk(rotation, posTo);
  if (state.isAttacking()) {
    Position pos = view->getPos();
    delete top;
    top = VistasFactory::getVehicleTopVista(type, color, pos);
  }
  state.moving();
}

void VehicleView::still() {
  UnitView::still();

  if (state.isAttacking()) {
    Position pos = view->getPos();
    delete top;
    top = VistasFactory::getVehicleTopVista(type, color, pos);
  }
  state.still();
}

void VehicleView::fire(const Position &huntedPos) {
  Position pos = view->getPos();
  int rotation = pos.getRoration(huntedPos);
  std::string rotation_s = std::to_string(rotation);
  delete top;
  top = VistasFactory::getVehicleTopStillVista(type, color, rotation_s, pos);
  top->setRotation(rotation);
  state.attacking();
}

void VehicleView::draw(SDL_Renderer *render, Camera &camera) {
  view->draw(render, camera);
  if (type == V_LTANK) {
    top->setPos(view->getDrawPosition());
    top->draw(render, camera);
  }
}
