#include "Quit.h"

Quit::Quit(Vista &vista) : Handler(vista) {}

void Quit::handle(SDL_Event *e) {
    vista.setQuit();
}
