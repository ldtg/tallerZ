#include "QuitEvent.h"

QuitEvent::QuitEvent(Model &model, View &view) : Event(model, view) {}

void QuitEvent::process() {
  view.setQuit();
}
