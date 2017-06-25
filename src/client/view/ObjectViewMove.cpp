#include <iostream>
#include "ObjectViewMove.h"
#include "ViewFactory.h"

ObjectViewMove::ObjectViewMove(Sprite *view) : view(view) {
  lastMove = false;
  state.still();
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
    ViewPosition pos = view->getViewPos();
    Position currentPos = pos.getPos();

    ViewPosition viewPosTo = movements.front();
    movements.pop();
    Position posTo = viewPosTo.getPos();

    // Ya llego al destino.
    if (currentPos == posTo && lastMove) {
      still();
      lastMove = false;
      // Se vacia la cola de movimientos.
      while (!movements.empty()) {movements.pop();}
      return;
    }

    int rotation = view->getDrawRotation();
    if (state.isStill() || state.isAttacking()) {
//      std::cout << "WALK" << std::endl;
//      std::cout << currentPos.getX() << " " << currentPos.getY() << std::endl;
//      std::cout << posTo.getX() << " " << posTo.getY() << std::endl;
//      std::cout << " " << std::endl;
//      std::cout << "movs: " << movements.size() << std::endl;

      walk(rotation, currentPos);
      state.moving();
    }

    int newRotation = pos.getDrawRoration(viewPosTo);
    if (rotation != newRotation) {
      walk(newRotation, posTo);
    }
    else {
      view->setPos(viewPosTo);
    }

//    double rot = pos.getRotation(viewPosTo);
//    view->setRotation(rot);
  }
}
