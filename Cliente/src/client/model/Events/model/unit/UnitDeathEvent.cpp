#include <client/view/explosion/UnitDeathView.h>
#include "UnitDeathEvent.h"

UnitDeathEvent::UnitDeathEvent(UnitID id) : id(id) {}

void UnitDeathEvent::process() {
  UnitView *unitVista = view->getUnitView(id);
  ExplosionView *deathView = new UnitDeathView(id.getType(), unitVista);

  view->removeUnitView(id);
  view->addExplosionView(deathView);

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
}
