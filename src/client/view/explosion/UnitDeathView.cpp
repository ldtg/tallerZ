#include "UnitDeathView.h"
#include "client/view/ViewFactory.h"

UnitDeathView::UnitDeathView(UnitType type, const UnitView *unitView) {
  Position pos = unitView->getPos();
  int rotation = 0;
  std::string color = unitView->getColor();

  std::string rotation_s = std::to_string(rotation);
  std::string action("die");
  deathView = ViewFactory::getUnitAnimation(type, color, action,
                                            rotation_s, pos);
}

UnitDeathView::~UnitDeathView() {
  delete deathView;
}

bool UnitDeathView::doCycle() const {
  return deathView->doCycle();
}

void UnitDeathView::draw(SDL_Renderer *render, Camera &camera) {
  deathView->draw(render, camera);
}
