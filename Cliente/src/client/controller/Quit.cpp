#include <client/model/Events/view/QuitEvent.h>
#include "Quit.h"

Quit::Quit() : Handler() {}

void Quit::handle(SDL_Event *e, EventHandler &eventHandler) {
  eventHandler.add(new QuitEvent());
}
