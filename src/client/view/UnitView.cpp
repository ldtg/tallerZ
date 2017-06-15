#include "UnitView.h"
#include "VistasFactory.h"

UnitView::UnitView(UnitType type, std::string &color, Position pos,
                   std::string &action, std::string &rotation)
    : type(type), color(color) {
  view = VistasFactory::getUnitVista(type, color, action,
                                     rotation, pos);
}

Position UnitView::getPos() const {
  if (!movements.empty()) {
    return movements.back().getPos();
  }
  else {
    return view->getPos();
  }
}

ViewPosition UnitView::getViewPos() const {
  if (!movements.empty()) {
    return movements.back();
  }
  else {
    return view->getViewPos();
  }
}

void UnitView::addMove(const ViewPosition &pos) {
  movements.push(pos);
}

void UnitView::update() {
  if (!movements.empty()) {
    ViewPosition viewPosTo = movements.front();
    movements.pop();
    Position posTo = viewPosTo.getPos();

//    Position pos = view->getPos();
    ViewPosition pos = view->getViewPos();
    int newRotation = pos.getRoration(viewPosTo);
    int rotation = view->getRotation();

    if (rotation != newRotation) {
      delete view;

      std::string rotation_s = std::to_string(newRotation);
      std::string action("walk");
      view = VistasFactory::getUnitVista(type, color, action,
                                         rotation_s, posTo);
      view->setRotation(newRotation);
      view->setPos(viewPosTo);
    }
    else {
      view->setPos(viewPosTo);
    }

  }
}

Sprite* UnitView::getView() {
  return view;
}
