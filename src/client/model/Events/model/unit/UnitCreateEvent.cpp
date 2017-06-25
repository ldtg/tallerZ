#include <client/view/sounds/SoundsFactory.h>
#include <client/view/unit/VehicleView.h>
#include "UnitCreateEvent.h"

UnitCreateEvent::UnitCreateEvent(UnitID id, UnitState state)
    : id(id), state(state) {}

void UnitCreateEvent::process() {
  std::string rotation_s("270");
  std::string action("create");
  std::string color = state.owner.getColor();
  UnitType type = id.getType();

  UnitView *unitVista = ViewFactory::getUnitView(type, color,
                                                   action, rotation_s,
                                                   state.position);
  unitVista->getView()->setDrawRotation(270);
  unitVista->create();
  view->addUnitView(id, unitVista);

  Map &map = model->getMap();
  map.addUnit(id, state);

//  SoundPlayer &soundPlayer = view->getSoundPlayer();
//  Sound *sound = SoundsFactory::getUnitCreateSound(id.getType());
//  soundPlayer.add(sound);
}
