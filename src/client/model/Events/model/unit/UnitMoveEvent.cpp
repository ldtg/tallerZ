
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

//  if (step.getX()<1.0 && step.getY()<1.0)

  std::cout << "DIST" << std::endl;
  std::cout << dist.getX() << " " << dist.getY() << std::endl;
  std::cout << "STEP" << std::endl;
  std::cout << step.getX() << " " << step.getY() << std::endl;
  std::cout << " " << std::endl;

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
