#include "FortView.h"
#include "client/view/ViewFactory.h"

FortView::FortView(const Position &pos, const std::string &color)
    : BuildingView(FORT, pos, color) {

  flag = ViewFactory::getFlagsVista(color, pos);
  flag->setPos(pos.add(55,26).sub(3,24));
}

FortView::~FortView() {
  if (flag != nullptr) delete flag;
}

void FortView::capture(const std::string &color) {}

void FortView::destroyed() {
  BuildingView::destroyed();


  Sprite *deathEffect2 = ViewFactory::getEffectVista(FIRE_EFFECT, pos);
  deathEffect2->setPos(pos.add(3 * BUILDWIDHT / 4 - 5, BUILDHEIGHT / 4));
  deathEffects.push_back(deathEffect2);

  Sprite *deathEffect3 = ViewFactory::getEffectVista(BIG_SMOKE, pos);
  deathEffect3->setPos(pos.add(3 * BUILDWIDHT / 4 - 15, 0).sub(0,15));
  deathEffects.push_back(deathEffect3);

  Sprite *deathEffect4 = ViewFactory::getEffectVista(FIRE_SMOKE, pos);
  deathEffect4->setPos(pos.add(BUILDWIDHT / 4, 3 * BUILDHEIGHT / 4 - 5));
  deathEffects.push_back(deathEffect4);
}

void FortView::draw(SDL_Renderer *render, Camera &camera) {
  BuildingView::draw(render, camera);
  flag->draw(render, camera);
}
