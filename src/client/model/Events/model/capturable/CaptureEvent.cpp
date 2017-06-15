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
  Sprite *capturerVista = view->getUnitVista(capturer);
//    Position pos = unitVista->getPos();
  std::string color = capturerVista->getColor();
  if (capturerDissapear) {
    view->removeUnitVista(capturer);
    model->getMap().removeCapturable(captured);
  }

//  if (!capturedUnits.empty()) {
  if (captured.getType() == UNIT) {
    std::string action("look_around");
//    std::string rotation("0");
    for (auto par: capturedUnits) {
      UnitType type = par.first.getType();
      Sprite *capturedVistaOld = view->getUnitVista(par.first);
      int rotation = capturedVistaOld->getRotation();
      std::string rotation_s = std::to_string(rotation);

      UnitView
          capturedVista(type, color, par.second.position, action, rotation_s);

      view->removeUnitVista(par.first);
      view->addUnitVista(par.first, capturedVista);
    }
  } else {
    ObjectMapaVista *flagVista = view->getCapturedVista(captured);
    Position pos = flagVista->getPos();
    view->removeCapturableVista(captured);
    Sprite *flag = VistasFactory::getFlagsVista(color, pos);
//    flag->setPos(capturedPosition);
    view->addCapturableVista(captured, flag);
  }
  for (auto par :capturedUnits) {
    model->getMap().updateUnit(par.first, par.second);
  }
  for (auto par :capturedBuilds) {
    model->getMap().updateBuild(par.first, par.second);
  }
}
