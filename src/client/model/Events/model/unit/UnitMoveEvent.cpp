
#include "UnitMoveEvent.h"

UnitMoveEvent::UnitMoveEvent(UnitID id, Position posTo)
    : id(id), posTo(posTo) {}

void UnitMoveEvent::process() {
  UnitView *unitView = view->getUnitView(id);
  Position unitPos = unitView->getPos();

  Position dist = posTo.sub(unitPos);
  // La velocidad de la vista respecto al server
  float velView = 4.0;
  ViewPosition step(dist.getX()/velView, dist.getY()/velView);

  ViewPosition unitViewPos = unitView->getViewPos();
  for (int i=0; i < velView; i++) {
    unitViewPos.add(step);
    unitView->addMove(unitViewPos);
  }

  Map &map = model->getMap();
  UnitState state = map.getUnitState(id);
  state.position = posTo;
  map.updateUnit(id, state);
}
