#include <client/view/sounds/SoundsFactory.h>
#include "UnitDeathEvent.h"

UnitDeathEvent::UnitDeathEvent(UnitID id) : id(id) {}

void UnitDeathEvent::process() {
  UnitView *unitVista = view->getUnitView(id);
  Position pos = unitVista->getPos();
  int rotation = 0;
  std::string color = unitVista->getColor();

  std::string rotation_s = std::to_string(rotation);
  std::string action("die");
  Sprite *deathVista = VistasFactory::getUnitVista(id.getType(), color,
                                                   action, rotation_s, pos);
  view->removeUnitVista(id);
  view->addExplosionVista(deathVista);
  model->getMap().removeUnit(id);

  //si esta en el sideboard hay que borrarlo
  auto unitsSelected = model->getUnitsSelected();
  for (auto iterator = unitsSelected.begin(); iterator != unitsSelected.end();
      ) {
    if (*iterator == id) {
      iterator = unitsSelected.erase(iterator);
      view->clear_unit_side_details();
      model->clearUnitsSelected();
    } else {
      ++iterator;
    }
  }
//  SoundPlayer &soundPlayer = view->getSoundPlayer();
//  Sound *sound = SoundsFactory::getTargetDestroyedSound();
//  soundPlayer.add(sound);
}
