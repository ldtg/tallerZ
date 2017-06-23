#include <client/view/sounds/SoundsFactory.h>
#include <client/view/UnitDeathView.h>
#include "UnitDeathEvent.h"

UnitDeathEvent::UnitDeathEvent(UnitID id) : id(id) {}

void UnitDeathEvent::process() {
  UnitView *unitVista = view->getUnitView(id);
  ExplosionView *deathView = new UnitDeathView(id.getType(), unitVista);

  view->removeUnitVista(id);
  view->addExplosionVista(deathView);

  model->getMap().removeUnit(id);

  //si esta en el sideboard hay que borrarlo
  auto unitsSelected = model->getUnitsSelected();
  for (auto iterator = unitsSelected.begin(); iterator != unitsSelected.end();) {
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
