#include "BulletMoveEvent.h"

BulletMoveEvent::BulletMoveEvent(const BulletID &id, const Position &to)
    : id(id), posTo(to) {}

void BulletMoveEvent::process() {
  BulletView *bulletView = view->getBulletView(id);
  Position bulletPos = bulletView->getPos();

  Position dist = posTo.sub(bulletPos);
  // La velocidad de la vista respecto al server
  float velView = 4.0;
  ViewPosition step(dist.getX()/velView, dist.getY()/velView);

  ViewPosition bulletViewPos = bulletView->getViewPos();
  for (int i=0; i < velView; i++) {
    bulletViewPos.add(step);
    bulletView->addMove(bulletViewPos);
  }

  Map &map = model->getMap();
  BulletState state = map.getBulletState(id);
  state.position = posTo;
  map.updateBullet(id, state);
}
