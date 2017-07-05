#include "LaserHitView.h"
#include "client/view/ViewFactory.h"

LaserHitView::LaserHitView(const Position &pos) {
  explosion = ViewFactory::getEffectVista(LASER_EFFECT, pos);
}

LaserHitView::~LaserHitView() {
  delete explosion;
}

bool LaserHitView::doCycle() const {
  return explosion->doCycle();
}

void LaserHitView::draw(SDL_Renderer *render, Camera &camera) {
  explosion->draw(render, camera);
}
