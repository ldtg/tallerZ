#include <iostream>
#include "UnitView.h"
#include "client/view/ViewFactory.h"

UnitView::UnitView(const UnitType &type, const std::string &color,
                   const Position &pos, std::string &action,
                   const std::string &rotation)
    : ObjectViewMove(ViewFactory::getUnitAnimation(type, color, action, rotation, pos)),
      type(type), color(color) {}

UnitView::~UnitView() {
  delete view;
}

void UnitView::create() {
  state.creating();
}

void UnitView::walk(int rotation, const Position &posTo) {
  std::string rotation_s = std::to_string(rotation);
  std::string action("walk");

  delete view;
  view = ViewFactory::getUnitAnimation(type, color, action,
                                       rotation_s, posTo);
  view->setDrawRotation(rotation);
}

void UnitView::still() {
  int rotation = view->getDrawRotation();
  Position pos = view->getPos();
  std::string rotation_s = std::to_string(rotation);
  std::string action("look_around");

  delete view;
  view = ViewFactory::getUnitAnimation(type, color, action, rotation_s, pos);
  view->setDrawRotation(rotation);
}

void UnitView::fire(const Position &huntedPos) {
  // Llego, entonces se vacia la cola de movimientos.
  while (!movements.empty()) {movements.pop();}

  Position pos = view->getPos();
  int rotation = pos.getRoration(huntedPos);
  std::string rotation_s = std::to_string(rotation);
  std::string action("fire");
  delete view;
  view = ViewFactory::getUnitAnimation(type, color, action, rotation_s, pos);
  view->setDrawRotation(rotation);
}

Sprite* UnitView::getView() const {
  return view;
}

std::string UnitView::getColor() const {
  return color;
}

void UnitView::draw(SDL_Renderer *render, Camera &camera) {
  view->draw(render, camera);
}
