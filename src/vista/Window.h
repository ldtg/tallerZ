#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <vector>
#include "Sprite.h"

class Window {
    private:
        SDL_Window *window;
        SDL_Renderer *window_render;
        Sprite *sprite;
        int width;
        int height;
    public:
        Window();
        ~Window();
        void load(Sprite *sprite);
        void draw();
};

#endif //WINDOW_H
