#include "Mouse.h"

#include <iostream>

Mouse::Mouse(Vista &vista) : Handler(vista) {}

void Mouse::handle(SDL_Event *e) {
    SDL_GetMouseState(&x, &y);
    std::cout << "(" << x << "," << y << ")" << std::endl;
}
