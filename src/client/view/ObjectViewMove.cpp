#include <iostream>
#include "ObjectViewMove.h"
#include "VistasFactory.h"

ObjectViewMove::ObjectViewMove(Sprite *view) : view(view) {
  lastMove = false;
}

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

void ObjectViewMove::setLastMove() {
  lastMove = true;
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
    Position currentPos = pos.getPos();

    // Ya llego al destino.
    if (currentPos == posTo && lastMove) {
      still();
      lastMove = false;
      // Se vacia la cola de movimientos.
      while (!movements.empty()) {movements.pop();}
      return;
    }

    int newRotation = pos.getRoration(viewPosTo);
    int rotation = view->getRotation();

    if (rotation != newRotation) {
      std::cout << "ROTO" << std::endl;

      walk(newRotation, posTo);
    }
    else {
      view->setPos(viewPosTo);
    }
  }

}
