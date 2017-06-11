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
  Sprite* capturerVista = view->getUnitVista(capturer);
//    Position pos = unitVista->getPos();
  std::string color = capturerVista->getColor();

  if (capturerDissapear) {
    view->removeUnitVista(capturer);
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
      Sprite *capturedVista = VistasFactory::getUnitVista(type, color,
                                                          action, rotation_s,
                                                          par.second.position);
//      capturedVista->setPos(par.second.position);
      view->removeUnitVista(par.first);
      view->addUnitVista(par.first, capturedVista);
    }
//    view->removeCapturableVista(captured);
  }
  else {
    ObjectMapaVista *flagVista = view->getCapturedVista(captured);
    Position pos = flagVista->getPos();
    view->removeCapturableVista(captured);
    Sprite *flag = VistasFactory::getFlagsVista(color, pos);
//    flag->setPos(capturedPosition);
    view->addCapturableVista(captured, flag);
  }
}
