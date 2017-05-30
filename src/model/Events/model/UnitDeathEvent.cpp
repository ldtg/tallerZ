#include "UnitDeathEvent.h"

UnitDeathEvent::UnitDeathEvent(UnitID id) :id(id){}

void UnitDeathEvent::process() {
  ObjectMapaVista* unitVista = view->getUnitVista(id);
  Position pos = unitVista->getPos();
  int rotation = 0;

  view->removeUnitVista(id);

  std::string rotation_s = std::to_string(rotation);
  std::string action("die");
  ObjectMapaVista *explosionVista = view->getUnitVista(id.getType(), action, rotation_s);
  explosionVista->setRotation(rotation);

  if (id.getType() == V_JEEP) {
    explosionVista->setPos(pos.sub(0,10));
//    explosionVista->setPos(pos);
    view->addUnitVista(id, explosionVista);
  }
  else
    view->addExplosionVista(explosionVista, pos);

}
