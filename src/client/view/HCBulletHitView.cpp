#include "HCBulletHitView.h"
#include "VistasFactory.h"

HCBulletHitView::HCBulletHitView(Position &pos) {
  explosion1 = VistasFactory::getEffectVista(TANK_MISSILE, pos);
  Position pos2 = pos.add(0,12);
  explosion2 = VistasFactory::getEffectVista(TANK_MISSILE, pos2);
}

HCBulletHitView::~HCBulletHitView() {
  delete explosion1;
  delete explosion2;
}

bool HCBulletHitView::doCycle() const {
  return explosion1->doCycle() && explosion2->doCycle();
}

void HCBulletHitView::draw(SDL_Renderer *render, Camera &camera) {
  explosion1->draw(render, camera);
  explosion2->draw(render, camera);
}
