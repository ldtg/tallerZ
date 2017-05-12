#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"
#include "Image.h"
#include <string>

class Sprite {
    protected:
        int num_frames;
        int cur_frame;
        int x;
        int y;
        std::string filename;
    public:
        Sprite();
        Sprite(const char *file, int num_frames);
        Sprite(Sprite &&other);
        Sprite& operator=(Sprite &&other);
        virtual ~Sprite();
        void set_texture(SDL_Renderer *render);
        virtual void draw(SDL_Renderer *render, int window_w, int window_h);
        void move(int x, int y);
};

#endif //SPRITE_H
