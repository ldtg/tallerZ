#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include "ObjectMapaVista.h"

class Image : public ObjectMapaVista {
    private:
        SDL_Surface *surface;
        SDL_Texture *texture;
//        int width;
//        int height;
//        int x;
//        int y;
    public:
        Image();
        Image(const char *file);
        Image(const char *file, int width, int height);
        Image(Image &&other);
        Image& operator=(Image &&other);
        ~Image();
        void setPos(int x, int y);
        void set_texture(SDL_Renderer *render);
        void draw(SDL_Renderer *render);
//        void draw(SDL_Renderer *render, int window_w, int window_h,
//                  int x, int y);
};

#endif //IMAGE_H
