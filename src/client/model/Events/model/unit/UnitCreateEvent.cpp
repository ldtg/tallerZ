#include <client/view/sounds/SoundsFactory.h>
#include <client/view/VehicleView.h>
#include "UnitCreateEvent.h"

UnitCreateEvent::UnitCreateEvent(UnitID id, UnitState state)
    : id(id), state(state) {}

void UnitCreateEvent::process() {
  std::string rotation_s("270");
  std::string action("create");
  std::string color = state.owner.getColor();
  UnitType type = id.getType();

  UnitView *unitVista = nullptr;
  if (type == R_GRUNT || type == R_TOUGH || type == R_PYRO
      || type == R_LASER || type == R_PSYCHO) {
    unitVista = new UnitView(type, color, state.position,
                             action, rotation_s);
  }
  else if (type == V_JEEP || type == V_LTANK) {
    unitVista = new VehicleView(type, color, state.position,
                                action, rotation_s);
  }
  unitVista->getView()->setRotation(270);

  view->addUnitVista(id, unitVista);

  Map &map = model->getMap();
  map.addUnit(id, state);

//  SoundPlayer &soundPlayer = view->getSoundPlayer();
//  Sound *sound = SoundsFactory::getUnitCreateSound(id.getType());
//  soundPlayer.add(sound);
}
