#include "UnitCreateEvent.h"

UnitCreateEvent::UnitCreateEvent(UnitID id, UnitState state)
    : id(id), state(state) {}

void UnitCreateEvent::process() {
  std::string rotation_s("270");
  std::string action("create");
  std::string color = state.owner.getColor();
  Sprite *unitCreateVista = VistasFactory::getUnitVista(id.getType(), color,
                                                        action, rotation_s,
                                                        state.position);
//  unitCreateVista->setPos(state.position);

  view->addUnitVista(id, unitCreateVista);
}
