#include "FireHitView.h"
#include "client/view/ViewFactory.h"

FireHitView::FireHitView(const Position &pos) {
  explosion1 = ViewFactory::getEffectVista(FIRE2_EFFECT, pos);
  Position pos2 = pos.sub(0,4);
  explosion2 = ViewFactory::getEffectVista(FIRE_EFFECT, pos2);
}

FireHitView::~FireHitView() {
  delete explosion1;
  delete explosion2;
}

bool FireHitView::doCycle() const {
  return explosion1->doCycle() && explosion2->doCycle();
}

void FireHitView::draw(SDL_Renderer *render, Camera &camera) {
  explosion1->draw(render, camera);
  explosion2->draw(render, camera);
}
