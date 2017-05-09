#include <algorithm>
#include <iostream>
#include "Sprite.h"

Sprite::Sprite() {}

Sprite::Sprite(const char *file, int num_frames) : image(file) {
    this->num_frames = num_frames;
    cur_frame = 0;
    x = 0;
    y = 0;
    clip = new SDL_Rect[num_frames];

    //Set sprite clips
    clip[ 0 ].x =  61;
    clip[ 0 ].y =  1934;
    clip[ 0 ].w =  35;
    clip[ 0 ].h =  55;

    clip[ 1 ].x =  115;
    clip[ 1 ].y =  1934;
    clip[ 1 ].w =  35;
    clip[ 1 ].h =  55;

    clip[ 2 ].x =  188;
    clip[ 2 ].y =  1934;
    clip[ 2 ].w =  35;
    clip[ 2 ].h =  55;

    clip[ 3 ].x = 241;
    clip[ 3 ].y = 1927;
    clip[ 3 ].w = 74;
    clip[ 3 ].h = 70;

    clip[ 4 ].x = 328;
    clip[ 4 ].y = 1906;
    clip[ 4 ].w = 100;
    clip[ 4 ].h = 108;

    clip[ 5 ].x = 443;
    clip[ 5 ].y = 1891;
    clip[ 5 ].w = 143;
    clip[ 5 ].h = 128;

    clip[ 6 ].x = 18;
    clip[ 6 ].y = 2017;
    clip[ 6 ].w = 143;
    clip[ 6 ].h = 126;

    clip[ 7 ].x = 187;
    clip[ 7 ].y = 2017;
    clip[ 7 ].w = 143;
    clip[ 7 ].h = 129;

    clip[ 8 ].x = 341;
    clip[ 8 ].y = 2017;
    clip[ 8 ].w = 143;
    clip[ 8 ].h = 129;

/*
    //Set sprite clips
    clip[ 0 ].x =   0;
    clip[ 0 ].y =   0;
    clip[ 0 ].w =  64;
    clip[ 0 ].h = 205;

    clip[ 1 ].x =  64;
    clip[ 1 ].y =   0;
    clip[ 1 ].w =  64;
    clip[ 1 ].h = 205;

    clip[ 2 ].x = 128;
    clip[ 2 ].y =   0;
    clip[ 2 ].w =  64;
    clip[ 2 ].h = 205;

    clip[ 3 ].x = 196;
    clip[ 3 ].y =   0;
    clip[ 3 ].w =  64;
    clip[ 3 ].h = 205;
*/
}

Sprite::Sprite(Sprite &&other) {
    this->num_frames = other.num_frames;
    this->cur_frame = other.cur_frame;
    this->x = other.x;
    this->y = other.y;
    this->image = std::move(other.image);
    this->clip = other.clip;

    other.num_frames = 0;
    other.cur_frame = 0;
    other.x = -1;
    other.y = -1;
    other.clip = NULL;
}

Sprite& Sprite::operator=(Sprite &&other) {
    this->num_frames = other.num_frames;
    this->cur_frame = other.cur_frame;
    this->x = other.x;
    this->y = other.y;
    this->image = std::move(other.image);
    this->clip = other.clip;

    other.num_frames = 0;
    other.cur_frame = 0;
    other.x = -1;
    other.y = -1;
    other.clip = NULL;

    return *this;
}

Sprite::~Sprite() {
    if (!clip) {
        delete[] clip;
    }
}

void Sprite::set_texture(SDL_Renderer *render) {
    image.set_texture(render);
}

void Sprite::draw(SDL_Renderer *render, int window_w, int window_h) {
    SDL_Rect *currentClip = &clip[cur_frame/(1*num_frames)];

//    std::cout << "x: " << x << " y: " << y << std::endl;
    image.draw(render, window_w, window_h, x, y, currentClip);

    ++cur_frame;
    //Cycle animation
    if (cur_frame/(1*num_frames) >= num_frames) {
        cur_frame = 0;
    }
}

void Sprite::move(int x, int y) {
    this->x += x;
    this->y += y;
}
