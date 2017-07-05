#include "BulletView.h"
#include "client/view/ViewFactory.h"

BulletView::BulletView(const WeaponType &type, const Position &from,
                       const Position &to)
    : ObjectViewMove(ViewFactory::getBulletVista(type, from)),
      type(type) {
  ViewPosition fromView(from.getX(), from.getY());
  ViewPosition toView(to.getX(), to.getY());
  double rotation = toView.getRotation(fromView);
  view->setRotation(rotation);
}

BulletView::~BulletView() {}

void BulletView::still() {}

void BulletView::walk(int rotation, const Position &posTo) {
  ViewPosition viewPos = view->getViewPos();

  delete view;
  view = ViewFactory::getBulletVista(type, posTo);

  ViewPosition viewPosTo(posTo.getX(), posTo.getY());
  double rot = viewPos.getRotation(viewPosTo);
  view->setRotation(rot);
}

Sprite *BulletView::getView() {
  return view;
}

void BulletView::draw(SDL_Renderer *render, Camera &camera) {
  view->draw(render, camera);
}
