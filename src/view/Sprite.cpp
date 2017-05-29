#include <algorithm>
#include <iostream>
#include "Sprite.h"
#include "Image.h"

Sprite::Sprite() {}

Sprite::Sprite(const char *file, int num_frames, int speed)
    : filename(file), num_frames(num_frames), speed(speed) {
    cur_frame = 0;
    x = 0;
    y = 0;
    _doCycle = false;
}

Sprite::~Sprite() {}

void Sprite::set_texture(SDL_Renderer *render) {}

void Sprite::draw(SDL_Renderer *render) {
    int cur_frame_aux = cur_frame/(speed*num_frames);

    std::string file_image = filename + std::to_string(cur_frame_aux)
                             + std::string(".png");

    Image image(file_image.c_str());
    image.setPos(Position(x, y));
    width = image.getWidth();
    height = image.getHeight();
    image.set_texture(render);
    image.draw(render);

    ++cur_frame;
    //Cycle animation
    if (cur_frame/(speed*num_frames) >= num_frames) {
        cur_frame = 0;
        _doCycle = true;
    }
}
