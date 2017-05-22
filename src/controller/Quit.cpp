#include <model/Events/QuitEvent.h>
#include "Quit.h"

Quit::Quit() : Handler() {}

void Quit::handle(SDL_Event *e, EventHandler &eventHandler,
                  Model &model, View &view) {
  eventHandler.add(new QuitEvent(model, view));
    // eventQueue.add(new QuitEvent);
//    vista.setQuit();
}
