#include "BuildingView.h"
#include "client/view/ViewFactory.h"

BuildingView::BuildingView(const BuildType &type, const Position &pos, const std::string &color)
    : building(ViewFactory::getBuildingImage(type,"",pos)),
      type(type), pos(pos), color(color) {}

BuildingView::~BuildingView() {
  delete building;

  for (Sprite *deathEffect : deathEffects)
    delete deathEffect;
}

void BuildingView::destroyed() {
  delete building;
  building = ViewFactory::getBuildingImage(type, "destroyed", pos);

  Sprite *deathEffect0 = ViewFactory::getEffectVista(FIRE_SMOKE, pos);
  deathEffect0->setPos(pos.add(BUILDWIDHT / 4, BUILDHEIGHT / 4));
  deathEffects.push_back(deathEffect0);

  Sprite *deathEffect1 = ViewFactory::getEffectVista(FIRE_EFFECT, pos);
  deathEffect1->setPos(pos.add(3 * BUILDWIDHT / 4, 3 * BUILDHEIGHT / 4));
  deathEffects.push_back(deathEffect1);
}

void BuildingView::draw(SDL_Renderer *render, Camera &camera) {
  building->draw(render, camera);

  for (Sprite *deathEffect : deathEffects)
    deathEffect->draw(render, camera);
}
