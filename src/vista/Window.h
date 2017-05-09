#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <vector>
#include "Image.h"
#include "Sprite.h"

class Window {
    private:
        SDL_Window *window;
        SDL_Renderer *window_render;
        SDL_Surface *screen_surface;
        Image image;
        Sprite *sprite;
        int width;
        int height;
    public:
        Window();
        void load_image(Image image);
        void load_sprite(Sprite *sprite);
        void draw();
        ~Window();
};

#endif //WINDOW_H
