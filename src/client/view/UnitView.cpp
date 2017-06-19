#include <iostream>
#include "UnitView.h"
#include "VistasFactory.h"

UnitView::UnitView(UnitType type, std::string &color, Position pos,
                   std::string &action, std::string &rotation)
    : ObjectViewMove(VistasFactory::getUnitVista(type, color, action, rotation, pos)),
      type(type), color(color) {}

UnitView::~UnitView() {
  delete view;
}

void UnitView::walk(int rotation, const Position &posTo) {
  std::string rotation_s = std::to_string(rotation);
  std::string action("walk");

  delete view;
  view = VistasFactory::getUnitVista(type, color, action,
                                     rotation_s, posTo);
  view->setRotation(rotation);
}

void UnitView::still() {
  int rotation = view->getRotation();
  Position pos = view->getPos();
  std::string rotation_s = std::to_string(rotation);
  std::string action("look_around");

  delete view;
  view = VistasFactory::getUnitVista(type, color, action, rotation_s, pos);
  view->setRotation(rotation);
}

void UnitView::fire(const Position &huntedPos) {
  Position pos = view->getPos();

  int rotation = pos.getRoration(huntedPos);
  std::string rotation_s = std::to_string(rotation);
  std::string action("fire");
  delete view;
  view = VistasFactory::getUnitVista(type, color, action, rotation_s, pos);
  view->setRotation(rotation);
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
