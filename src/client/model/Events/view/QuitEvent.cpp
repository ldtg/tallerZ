#include "QuitEvent.h"

void QuitEvent::process() {
  view->setQuit();
}
