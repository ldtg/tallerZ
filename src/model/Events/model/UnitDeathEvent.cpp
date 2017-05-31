#include "UnitDeathEvent.h"

UnitDeathEvent::UnitDeathEvent(UnitID id) :id(id){}

void UnitDeathEvent::process() {
  ObjectMapaVista* unitVista = view->getUnitVista(id);
  Position pos = unitVista->getPos();
  int rotation = 0;

  view->removeUnitVista(id);

  std::string rotation_s = std::to_string(rotation);
  std::string action("die");
  Sprite *explosionVista = view->getUnitVista(id.getType(), action, rotation_s);
  explosionVista->setPos(view->translatePos(id.getType(), action, pos));
  explosionVista->setRotation(rotation);

  if (id.getType() == V_JEEP) {
//    explosionVista->setPos(view->translatePos(id.getType(), action, pos));
//    explosionVista->setPos(pos);
    view->addUnitVista(id, explosionVista);
  }
  else
    view->addExplosionVista(explosionVista, pos);

}
