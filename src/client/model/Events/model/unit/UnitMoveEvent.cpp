
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
<<<<<<< HEAD

=======
>>>>>>> e1adad81d36da46f97655c92a759b2b129bab383
  ViewPosition unitViewPos = unitView->getViewPos();

  // Si el paso es menor a 0 en X e Y la unidad empieza a rotar en cada paso,
  // lo que hace que se vea mal. Entonces se mueve primero en X y luego en Y.
  if (step.getX()<1.0 && step.getY()<1.0) {
    while (unitPos != posTo) {
      unitPos.move(posTo);
      unitView->addMove(ViewPosition(unitPos.getX(),unitPos.getY()));
    }
  } else {
    for (int i=0; i < velView; i++) {
      unitViewPos.add(step);
      unitView->addMove(unitViewPos);
    }
  }

  Map &map = model->getMap();
  UnitState state = map.getUnitState(id);
  state.position = posTo;
  map.updateUnit(id, state);
}
