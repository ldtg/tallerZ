#include "UnitCreateEvent.h"

UnitCreateEvent::UnitCreateEvent(UnitID id, UnitState state)
    : id(id), state(state) {}

void UnitCreateEvent::process() {
  std::string rotation_s("270");
  std::string action2("create");
  ObjectMapaVista *unitCreateVista = view->getUnitVista(id.getType(), action2, rotation_s);
  unitCreateVista->setPos(state.position);

  view->addUnitVista(id, unitCreateVista);
}
