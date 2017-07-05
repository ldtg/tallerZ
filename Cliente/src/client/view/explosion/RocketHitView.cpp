#include "RocketHitView.h"
#include "client/view/ViewFactory.h"

RocketHitView::RocketHitView(const Position &pos) {
  explosion1 = ViewFactory::getEffectVista(TANK_MISSILE, pos);
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
