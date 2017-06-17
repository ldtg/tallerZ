#include <iostream>
#include "UnitView.h"
#include "VistasFactory.h"

UnitView::UnitView(UnitType type, std::string &color, Position pos,
                   std::string &action, std::string &rotation)
    : type(type), color(color) {
  view = VistasFactory::getUnitVista(type, color, action,
                                     rotation, pos);
}

UnitView::~UnitView() {
  delete view;
}
/*
Position UnitView::getPos() const {
  if (!movements.empty()) {
    return movements.back().getPos();
  } else {
    return view->getPos();
  }
}

ViewPosition UnitView::getViewPos() const {
  if (!movements.empty()) {
    return movements.back();
  } else {
    return view->getViewPos();
  }
}

void UnitView::addMove(const ViewPosition &pos) {
  movements.push(pos);
}
*/
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

/*
void UnitView::update() {
  if (!movements.empty()) {
    ViewPosition viewPosTo = movements.front();
    movements.pop();
    Position posTo = viewPosTo.getPos();

    ViewPosition pos = view->getViewPos();
    int newRotation = pos.getRoration(viewPosTo);
    int rotation = view->getRotation();

<<<<<<< HEAD
    std::cout << pos.getX() << " " << pos.getY() << std::endl;
    std::cout << viewPosTo.getX() << " " << viewPosTo.getY() << std::endl;
    std::cout << " " << std::endl;
    std::cout << "rot: " << rotation << std::endl;
    std::cout << "NEW rot: " << newRotation << std::endl;
    std::cout << " " << std::endl;

    if (rotation != newRotation) {
      walk(newRotation, posTo);
    }
    else {
=======
    if (rotation != newRotation) {
      delete view;
      std::string rotation_s = std::to_string(newRotation);
      std::string action("walk");
      view = VistasFactory::getUnitVista(type, color, action,
                                         rotation_s, posTo);
      view->setRotation(newRotation);
      view->setPos(viewPosTo);
    } else {
>>>>>>> 133bb92ccc2f7825deefdc83f1972a14454dfed4
      view->setPos(viewPosTo);
    }
  }
}
*/

Sprite* UnitView::getView() const {
  return view;
}

std::string UnitView::getColor() const {
  return color;
}
