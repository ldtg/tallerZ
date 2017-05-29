#include "UnitDeathEvent.h"

UnitDeathEvent::UnitDeathEvent(UnitID id) :id(id){}

void UnitDeathEvent::process() {
  ObjectMapaVista* unitVista = view->getUnitVista(id);
  Position pos = unitVista->getPos();
  int rotation = 0;

  view->removeUnitVista(id);

  std::string rotation_s = std::to_string(rotation);
  std::string action("die");
  ObjectMapaVista *explosionVista = view->getUnitVista(id.getType(), action, rotation_s, 5, 2);
  explosionVista->setRotation(rotation);

  view->addExplosionVista(explosionVista, pos);
}
