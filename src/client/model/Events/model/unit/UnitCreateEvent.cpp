#include <client/view/sounds/SoundsFactory.h>
#include "UnitCreateEvent.h"

UnitCreateEvent::UnitCreateEvent(UnitID id, UnitState state)
    : id(id), state(state) {}

void UnitCreateEvent::process() {
  std::string rotation_s("270");
  std::string action("create");
  std::string color = state.owner.getColor();
  UnitView *unitVista = new UnitView(id.getType(), color,
                                     state.position, action,
                                     rotation_s);
  view->addUnitVista(id, unitVista);

  Map &map = model->getMap();
  map.addUnit(id, state);

  SoundPlayer &soundPlayer = view->getSoundPlayer();
  Sound *sound = SoundsFactory::getUnitCreateSound(id.getType());
  soundPlayer.add(sound);
}
