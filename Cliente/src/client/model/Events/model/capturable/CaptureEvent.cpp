#include "CaptureEvent.h"

CaptureEvent::CaptureEvent(const UnitID &capturer,
                           const CapturableID &captured,
                           const Position capturedPosition,
                           const std::map<BuildID, BuildState> &capturedBuilds,
                           const std::map<UnitID, UnitState> &capturedUnits,
                           bool dissapear)
    : capturer(capturer),
      captured(captured),
      capturedPosition(capturedPosition),
      capturedBuilds(capturedBuilds),
      capturedUnits(capturedUnits),
      capturerDissapear(dissapear) {}

void CaptureEvent::process() {
  Sprite *capturerVista = view->getUnitView(capturer)->getView();
  std::string color = capturerVista->getColor();
  if (capturerDissapear) {
    view->removeUnitView(capturer);
  }

  if (captured.getType() == UNIT) {
    std::string action("look_around");
    for (auto par : capturedUnits) {
      UnitType type = par.first.getType();
      Sprite *capturedVistaOld = view->getUnitView(par.first)->getView();

      int rotation = capturedVistaOld->getDrawRotation();
      std::string rotation_s = std::to_string(rotation);
      UnitView *capturedVista = ViewFactory::getUnitView(type, color,
                                             action, rotation_s,
                                             par.second.position);
      capturedVista->getView()->setDrawRotation(rotation);
      view->removeUnitView(par.first);
      view->addUnitView(par.first, capturedVista);

      model->getMap().removeCapturable(captured);
    }
  } else {
    ObjectView *flagVista = view->getCapturedView(captured);
    Position pos = flagVista->getPos();
    view->removeCapturableView(captured);
    Sprite *flag = ViewFactory::getFlagsVista(color, pos);
    view->addCapturableView(captured, flag);

    for (auto par : capturedBuilds) {
      BuildingView *buildingView = view->getBuildingView(par.first);
      buildingView->capture(color);
    }
  }

  if (capturerDissapear) {
    model->getMap().removeCapturable(captured);
  }
  for (auto par : capturedUnits) {
    model->getMap().updateUnit(par.first, par.second);
  }
  for (auto par : capturedBuilds) {
    model->getMap().updateBuild(par.first, par.second);
  }
}
