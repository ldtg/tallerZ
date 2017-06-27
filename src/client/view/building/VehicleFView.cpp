#include "VehicleFView.h"
#include "client/view/ViewFactory.h"

VehicleFView::VehicleFView(const std::string &techLevel,
                           const Position &pos,
                           const std::string &color)
    : BuildingView(VEHICLEF, pos, color) {
  this->pos = pos;
  this->color = color;

  vehicle = ViewFactory::getBuildingEffectView(PRODUCT, "vehicle", pos);
  std::string path = "../src/view/images/buildings/level" + techLevel + ".png";
  levelFactory = new Image(path.c_str());
  levelFactory->setPos(pos.add(8,56));

  spin = nullptr;
  smoke = nullptr;
  vent = nullptr;
  bulb = nullptr;
  layoutColor = nullptr;
}

VehicleFView::~VehicleFView() {
  if (vehicle != nullptr) delete vehicle;
  if (levelFactory != nullptr) delete levelFactory;
  if (spin != nullptr) delete spin;
  if (smoke != nullptr) delete smoke;
  if (vent != nullptr) delete vent;
  if (bulb != nullptr) delete bulb;
  if (layoutColor != nullptr) delete layoutColor;
}

void VehicleFView::capture(const std::string &color) {
  this->color = color;

  spin = ViewFactory::getBuildingEffectView(SPIN, "vehicle", pos);
  smoke = ViewFactory::getBuildingEffectView(SMOKE, "vehicle", pos);
  vent = ViewFactory::getBuildingEffectView(VENT, "vehicle", pos);
  bulb = ViewFactory::getBuildingEffectView(BULB, "vehicle", pos);
  std::string path = "../src/view/images/buildings/vehicle/" + color + ".png";
  layoutColor = new Image(path.c_str());
  layoutColor->setPos(pos.add(32,48));
}

void VehicleFView::destroyed() {
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

  if (vehicle != nullptr) {
    delete vehicle;
    vehicle = nullptr;
  }
  if (spin != nullptr) {
    delete spin;
    spin = nullptr;
  }
  if (smoke != nullptr) {
    delete smoke;
    smoke = nullptr;
  }
  if (vent != nullptr) {
    delete vent;
    vent = nullptr;
  }
  if (bulb != nullptr) {
    delete bulb;
    bulb = nullptr;
  }
  if (layoutColor != nullptr) {
    delete layoutColor;
    std::string path = "../src/view/images/buildings/vehicle/"
        + color + "_destroyed.png";
    layoutColor = new Image(path.c_str());
    layoutColor->setPos(pos.add(16, 64));
  }
}

void VehicleFView::draw(SDL_Renderer *render, Camera &camera) {
  BuildingView::draw(render, camera);
  if (vehicle != nullptr) vehicle->draw(render, camera);
  if (levelFactory!= nullptr) levelFactory->draw(render, camera);

  if (spin!= nullptr) spin->draw(render, camera);
  if (smoke!= nullptr) smoke->draw(render, camera);
  if (vent!= nullptr) vent->draw(render, camera);
  if (layoutColor!= nullptr) layoutColor->draw(render, camera);
  if (bulb!= nullptr) bulb->draw(render, camera);
}
