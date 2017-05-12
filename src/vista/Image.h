#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>

class Image {
    private:
        SDL_Surface *surface;
        SDL_Texture *texture;
        int width;
        int height;
    public:
        Image();
        Image(const char *file);
        Image(const char *file, int width, int height);
        Image(Image &&other);
        Image& operator=(Image &&other);
        ~Image();
        void set_texture(SDL_Renderer *render);
        void draw(SDL_Renderer *render, int window_w, int window_h);
        void draw(SDL_Renderer *render, int window_w, int window_h,
                  int x, int y, SDL_Rect *clip);
};

#endif //IMAGE_H
