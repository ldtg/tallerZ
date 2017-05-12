#include <algorithm>
#include <iostream>
#include "Sprite.h"

Sprite::Sprite() {}

Sprite::Sprite(const char *file, int num_frames)
    : filename(file) {
    this->num_frames = num_frames;
    cur_frame = 0;
    x = 0;
    y = 0;
}

Sprite::Sprite(Sprite &&other) {
    this->num_frames = other.num_frames;
    this->cur_frame = other.cur_frame;
    this->x = other.x;
    this->y = other.y;

    other.num_frames = 0;
    other.cur_frame = 0;
    other.x = -1;
    other.y = -1;
}

Sprite& Sprite::operator=(Sprite &&other) {
    this->num_frames = other.num_frames;
    this->cur_frame = other.cur_frame;
    this->x = other.x;
    this->y = other.y;

    other.num_frames = 0;
    other.cur_frame = 0;
    other.x = -1;
    other.y = -1;

    return *this;
}

Sprite::~Sprite() {}

void Sprite::draw(SDL_Renderer *render, int window_w, int window_h) {
    int cur_frame_aux = cur_frame/(1*num_frames);

    std::string file_image = filename + std::to_string(cur_frame_aux)
                             + std::string(".png");

    Image image(file_image.c_str());
    image.set_texture(render);
    image.draw(render, window_w, window_h);

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
