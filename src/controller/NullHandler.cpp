#include "NullHandler.h"

NullHandler::NullHandler(Vista &vista) : Handler(vista) {}

void NullHandler::handle(SDL_Event *e) {}

