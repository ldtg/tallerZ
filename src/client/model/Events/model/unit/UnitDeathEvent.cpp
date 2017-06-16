#include "UnitDeathEvent.h"

UnitDeathEvent::UnitDeathEvent(UnitID id) : id(id) {}

void UnitDeathEvent::process() {
  Sprite *unitVista = view->getUnitVista(id);
  Position pos = unitVista->getPos();
  int rotation = 0;
  std::string color = unitVista->getColor();

  std::string rotation_s = std::to_string(rotation);
  std::string action("die");
  Sprite *explosionVista =
      VistasFactory::getUnitVista(id.getType(), color, action, rotation_s, pos);
  explosionVista->setRotation(rotation);
  view->removeUnitVista(id);
  view->addExplosionVista(explosionVista);

}
