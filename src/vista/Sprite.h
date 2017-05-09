#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"
#include "Image.h"

class Sprite {
    private:
        int num_frames;
        int cur_frame;
        int x;
        int y;
        Image image;
        SDL_Rect *clip;
    public:
        Sprite();
        Sprite(const char *file, int num_frames);
        Sprite(Sprite &&other);
        Sprite& operator=(Sprite &&other);
        ~Sprite();
        void set_texture(SDL_Renderer *render);
        void draw(SDL_Renderer *render, int window_w, int window_h);
        void move(int x, int y);
};

#endif //SPRITE_H
