#include "VehicleView.h"
#include "VistasFactory.h"

VehicleView::VehicleView(UnitType type, std::string &color,
                         Position pos, std::string &action,
                         std::string &rotation)
    : UnitView(type, color, pos, action, rotation) {
  top = VistasFactory::getVehicleTopVista(type, color, pos);
}

void VehicleView::draw(SDL_Renderer *render, Camera &camera) {
  view->draw(render, camera);
  if (type == V_LTANK) {
    top->setPos(view->getPos());
    top->draw(render, camera);
  }
}
