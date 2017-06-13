#include "UnitCreateEvent.h"

UnitCreateEvent::UnitCreateEvent(UnitID id, UnitState state)
    : id(id), state(state) {}

void UnitCreateEvent::process() {
  std::string rotation_s("270");
  std::string action("create");
  std::string color = state.owner.getColor();
  UnitView unitVista(id.getType(), color, state.position, action, rotation_s);

  model->getMap().addUnit(id, state);
  view->addUnitVista(id, unitVista);

  Map &map = model->getMap();
  map.addUnit(id, state);
}
