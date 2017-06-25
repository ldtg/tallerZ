#include <iostream>
#include "VehicleView.h"
#include "client/view/ViewFactory.h"

VehicleView::VehicleView(const UnitType &type, const std::string &color,
                         const Position &pos, std::string &action,
                         const std::string &rotation,
                         std::map<int, Position> &desp,
                         std::map<int, SDL_Point> &pointRotTop)
    : UnitView(type, color, pos, action, rotation),
      pointRotView(desp), pointRotTop(pointRotTop) {
  top = ViewFactory::getVehicleTopVista(type, color, pos);
}

VehicleView::~VehicleView() {
  delete top;
}

int VehicleView::getRotTop() const {
  int rot = top->getCurFrame();
  switch (rot) {
    case 0: return 0;
    case 1: return 45;
    case 2: return 90;
    case 3: return 135;
    case 4: return 180;
    case 5: return 225;
    case 6: return 270;
    case 7: return 315;
    default: return 0;
  }
}

void VehicleView::walk(int rotation, const Position &posTo) {
  UnitView::walk(rotation, posTo);
  if (state.isAttacking()) {
    Position pos = view->getPos();
    delete top;
    top = ViewFactory::getVehicleTopVista(type, color, pos);
  }
  state.moving();
}

void VehicleView::still() {
  UnitView::still();

  if (state.isAttacking()) {
    Position pos = view->getPos();
    delete top;
    top = ViewFactory::getVehicleTopVista(type, color, pos);
  }
  state.still();
}

void VehicleView::fire(const Position &huntedPos) {
//  UnitView::fire(huntedPos);
  // Llego, entonces se vacia la cola de movimientos.
  while (!movements.empty()) {movements.pop();}

  Position pos = view->getPos();
  int rotation = pos.getRoration(huntedPos);
  std::string rotation_s = std::to_string(rotation);
  delete top;
  top = ViewFactory::getVehicleTopFireVista(type, color, rotation_s, pos);
  top->setDrawRotation(rotation);
  state.attacking();
}

void VehicleView::draw(SDL_Renderer *render, Camera &camera) {
  view->draw(render, camera);

  int rot = view->getDrawRotation();
  Position desp = this->pointRotView.at(rot);
  int despX = (int) desp.getX();
  int despY = (int) desp.getY();
  top->setDesp(despX, despY);

  int rotTop = getRotTop();
  SDL_Point pointRot = pointRotTop.at(rotTop);
  top->setPointRotation(&pointRot);
  top->setDesp(pointRot.x-despX, pointRot.y-despY);

  top->setPos(view->getDrawPosition());
  top->draw(render, camera);
}
