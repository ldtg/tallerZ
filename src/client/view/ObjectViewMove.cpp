#include <iostream>
#include "ObjectViewMove.h"
#include "VistasFactory.h"

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
      walk(rotation, currentPos);
      state.moving();
    }

    double rot = pos.getRotation(viewPosTo);
    view->setRotation(rot);

    int newRotation = pos.getDrawRoration(viewPosTo);
    if (rotation != newRotation) {
      walk(newRotation, posTo);
    }
    else {
      view->setPos(viewPosTo);
    }
  }

}
