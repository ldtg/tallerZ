#include "Mouse.h"

#include <iostream>

Mouse::Mouse() : Handler() {}

void Mouse::handle(SDL_Event *e, EventHandler &eventHandler,
                   Model &model, View &view) {
    SDL_GetMouseState(&x, &y);
    std::cout << "(" << x << "," << y << ")" << std::endl;
}
