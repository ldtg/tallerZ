#include "BulletView.h"
#include "VistasFactory.h"

BulletView::BulletView(WeaponType type, std::string &rotation, Position pos)
    : type(type) {
  view = VistasFactory::getBulletVista(type, rotation, pos);
}

void BulletView::walk(int rotation, const Position &posTo) {
  std::string rotation_s = std::to_string(rotation);

  delete view;
  view = VistasFactory::getBulletVista(type, rotation_s, posTo);
}

Sprite* BulletView::getView() {
  return view;
}

void BulletView::draw(SDL_Renderer *render, Camera &camera) {
  view->draw(render, camera);
}
