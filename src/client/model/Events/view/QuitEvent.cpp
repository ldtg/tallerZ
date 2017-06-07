#include "QuitEvent.h"

//QuitEvent::QuitEvent() {}

void QuitEvent::process() {
  view->setQuit();
}
