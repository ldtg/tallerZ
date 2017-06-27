#include <iostream>
#include "ObjectViewMove.h"

ObjectViewMove::ObjectViewMove(Sprite *view) : view(view) {
  lastMove = false;
  state.still();
}

Position ObjectViewMove::getPos() const {
  if (!movements.empty()) {
    return movements.back().getPos();
  } else {
    return view->getPos();
  }
}

ViewPosition ObjectViewMove::getViewPos() const {
  if (!movements.empty()) {
    return movements.back();
  } else {
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
    if ( (currentPos == posTo || state.isAttacking())
       && lastMove) {
      still();
      lastMove = false;
      // Se vacia la cola de movimientos.
      while (!movements.empty()) { movements.pop(); }
      return;
    }

    int rotation = view->getDrawRotation();
    // Cuando realiza el primer movimiento se le debe avisar a la unidad,
    // porque si la rotacion no cambia esta no cambia la imagen a una de "walk".
    if (state.isStill() || state.isAttacking()) {
      walk(rotation, currentPos);
      state.moving();
    }

    int newRotation = pos.getDrawRoration(viewPosTo);
    if (rotation != newRotation) {
      walk(newRotation, posTo);
    } else {
      view->setPos(viewPosTo);
    }
  }
}
ObjectViewMove::~ObjectViewMove() {
  if (view != nullptr)
    delete view;
}
