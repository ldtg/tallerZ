#include "LaserHitView.h"
#include "VistasFactory.h"

LaserHitView::LaserHitView(Position &pos) {
  explosion = VistasFactory::getEffectVista(LASER_EFFECT, pos);
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
