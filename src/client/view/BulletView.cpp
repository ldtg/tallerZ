#include <iostream>
#include "BulletView.h"
#include "VistasFactory.h"

BulletView::BulletView(WeaponType type, Position from, Position to)
    : ObjectViewMove(VistasFactory::getBulletVista(type, from)),
      type(type) {
  ViewPosition fromView(from.getX(), from.getY());
  ViewPosition toView(to.getX(), to.getY());
  double rotation = toView.getRotation(fromView);
  view->setRotation(rotation);
}

void BulletView::still() {}

void BulletView::walk(int rotation, const Position &posTo) {
  ViewPosition viewPos = view->getViewPos();

  delete view;
  view = VistasFactory::getBulletVista(type, posTo);

  ViewPosition viewPosTo(posTo.getX(), posTo.getY());
  double rot = viewPos.getRotation(viewPosTo);
  view->setRotation(rot);
}

Sprite* BulletView::getView() {
  return view;
}

void BulletView::draw(SDL_Renderer *render, Camera &camera) {
  view->draw(render, camera);
}
