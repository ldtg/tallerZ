#include "ObjectViewMove.h"
#include "VistasFactory.h"

//ObjectViewMove::ObjectViewMove(ObjectMapaVista *view)
//    : view(view) {}

Position ObjectViewMove::getPos() const {
  if (!movements.empty()) {
    return movements.back().getPos();
  }
  else {
    return view->getPos();
  }
}

ViewPosition ObjectViewMove::getViewPos() const {
  if (!movements.empty()) {
    return movements.back();
  }
  else {
    return view->getViewPos();
  }
}

void ObjectViewMove::addMove(const ViewPosition &pos) {
  movements.push(pos);
}

void ObjectViewMove::update() {
  if (!movements.empty()) {
    ViewPosition viewPosTo = movements.front();
    movements.pop();
    Position posTo = viewPosTo.getPos();

    ViewPosition pos = view->getViewPos();
    int newRotation = pos.getRoration(viewPosTo);
    int rotation = view->getRotation();

    if (rotation != newRotation) {
      walk(newRotation, posTo);
    }
    else {
      view->setPos(viewPosTo);
    }
  }
}
