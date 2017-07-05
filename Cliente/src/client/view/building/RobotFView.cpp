#include "RobotFView.h"
#include "client/view/ViewFactory.h"

RobotFView::RobotFView(const std::string &techLevel,
                       const Position &pos,
                       const std::string &color)
    : BuildingView(ROBOTF, pos, color) {
  this->pos = pos;
  this->color = color;

  robot = ViewFactory::getBuildingEffectView(PRODUCT, "robot", pos);
  std::string path = "../src/view/images/buildings/level" + techLevel + ".png";
  levelFactory = new Image(path.c_str());
  levelFactory->setPos(pos.add(8,56));

  spin = nullptr;
  smoke = nullptr;
  box = nullptr;
  layoutColor = nullptr;
}

RobotFView::~RobotFView() {
  if (robot != nullptr) delete robot;
  if (levelFactory != nullptr) delete levelFactory;
  if (spin != nullptr) delete spin;
  if (smoke != nullptr) delete smoke;
  if (box != nullptr) delete box;
  if (layoutColor != nullptr) delete layoutColor;
}

void RobotFView::capture(const std::string &color) {
  this->color = color;

  spin = ViewFactory::getBuildingEffectView(SPIN, "robot", pos);
  smoke = ViewFactory::getBuildingEffectView(SMOKE, "robot", pos);
  box = ViewFactory::getBuildingEffectView(GREEN_BOX, "robot", pos);
  std::string path = "../src/view/images/buildings/robot/" + color + ".png";
  layoutColor = new Image(path.c_str());
  layoutColor->setPos(pos.add(16,64));
}

void RobotFView::destroyed() {
  BuildingView::destroyed();

  Sprite *deathEffect2 = ViewFactory::getEffectVista(FIRE_EFFECT, pos);
  deathEffect2->setPos(pos.add(3 * BUILDWIDHT / 4 - 25, BUILDHEIGHT / 4));
  deathEffects.push_back(deathEffect2);

  Sprite *deathEffect3 = ViewFactory::getEffectVista(BIG_SMOKE, pos);
  deathEffect3->setPos(pos.add(3 * BUILDWIDHT / 4 - 35, 0).sub(0,15));
  deathEffects.push_back(deathEffect3);

  Sprite *deathEffect4 = ViewFactory::getEffectVista(FIRE_SMOKE, pos);
  deathEffect4->setPos(pos.add(BUILDWIDHT / 4 - 25, 3 * BUILDHEIGHT / 4 - 5));
  deathEffects.push_back(deathEffect4);

  if (robot != nullptr) {
    delete robot;
    robot = nullptr;
  }
  if (spin != nullptr) {
    delete spin;
    spin = nullptr;
  }
  if (smoke != nullptr) {
    delete smoke;
    smoke = nullptr;
  }
  if (box != nullptr) {
    delete box;
    box = nullptr;
  }
  if (layoutColor != nullptr) {
    delete layoutColor;
    std::string path = "../src/view/images/buildings/robot/"
                       + color + "_destroyed.png";
    layoutColor = new Image(path.c_str());
    layoutColor->setPos(pos.add(16,64));
  }
}

void RobotFView::draw(SDL_Renderer *render, Camera &camera) {
  BuildingView::draw(render, camera);
  if (robot != nullptr) robot->draw(render, camera);
  if (levelFactory!= nullptr) levelFactory->draw(render, camera);

  if (spin!= nullptr) spin->draw(render, camera);
  if (smoke!= nullptr) smoke->draw(render, camera);
  if (box!= nullptr) box->draw(render, camera);
  if (layoutColor!= nullptr) layoutColor->draw(render, camera);
}
