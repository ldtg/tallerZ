#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <vector>

class Window {
    private:
        SDL_Window *window;
        SDL_Renderer *window_render;
        int width;
        int height;
    public:
        Window();
        ~Window();
        SDL_Renderer *getRender() const;
};

#endif //WINDOW_H
