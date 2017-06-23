#include "RocketHitView.h"
#include "VistasFactory.h"

RocketHitView::RocketHitView(Position &pos) {
  explosion1 = VistasFactory::getEffectVista(TANK_MISSILE, pos);
}

RocketHitView::~RocketHitView() {
  delete explosion1;
}

bool RocketHitView::doCycle() const {
  return explosion1->doCycle();
}

void RocketHitView::draw(SDL_Renderer *render, Camera &camera) {
  explosion1->draw(render, camera);
}
