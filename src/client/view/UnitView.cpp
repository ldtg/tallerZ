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
    return movements.back();
  }
  else {
    return view->getPos();
  }
}

void UnitView::addMove(const Position &pos) {
  movements.push(pos);
}

void UnitView::update() {
  if (!movements.empty()) {
    Position posTo = movements.front();
    movements.pop();

    Position pos = view->getPos();
    int newRotation = pos.getRoration(posTo);
    int rotation = view->getRotation();

    if (rotation != newRotation) {
      delete view;

      std::string rotation_s = std::to_string(newRotation);
      std::string action("walk");
      view = VistasFactory::getUnitVista(type, color, action,
                                         rotation_s, posTo);
      view->setRotation(newRotation);
    }
    else {
      view->setPos(posTo);
    }

  }
}

Sprite* UnitView::getView() {
  return view;
}
