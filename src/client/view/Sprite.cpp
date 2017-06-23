#include <algorithm>
#include <iostream>
#include "Sprite.h"

Sprite::Sprite() {}

Sprite::Sprite(const char *file, int num_frames, int speed,
               int num_frame_return_cycle, std::string color,
               int despX, int despY)
    : filename(file), num_frames(num_frames), speed(speed),
      color(color), despX(despX), despY(despY) {

  cur_frame = 0;
  this->num_frame_return_cycle =
      (num_frames - (num_frames - num_frame_return_cycle)) * speed;
  x = 0;
  y = 0;
  _doCycle = false;

  for (int frame = 0; frame < num_frames; ++frame) {
    std::string file_image = filename + std::to_string(frame) + ".png";
    Image *image = new Image(file_image.c_str());
    images.push_back(image);
  }
}

Sprite::~Sprite() {
  for (unsigned long frame = 0; frame < num_frames; ++frame) {
    delete (images.at(frame));
  }
}

bool Sprite::doCycle() const {
  return _doCycle;
}

std::string Sprite::getColor() const {
  return color;
}

void Sprite::scale(float scaleW, float scaleH) {
  for (int frame = 0; frame < num_frames; ++frame) {
    images[frame]->scale(scaleW, scaleH);
  }
}

void Sprite::setDesp(const int despX, const int despY) {
  this->despX = despX;
  this->despY = despY;
}

void Sprite::set_texture(SDL_Renderer *render) {}

ViewPosition Sprite::getDrawPosition() const {
  return ViewPosition(x-despX, y-despY);
}

void Sprite::setRotation(double rotation) {
  for (int frame = 0; frame < num_frames; ++frame) {
    images[frame]->setRotation(rotation);
  }
}

int Sprite::getCurFrame() const {
  return cur_frame/speed;
}

void Sprite::draw(SDL_Renderer *render, Camera &camera) {
  int cur_frame_aux = 0;
  if (speed > 0)
    cur_frame_aux = cur_frame / speed;

  images[cur_frame_aux]->setPos(ViewPosition(x-despX, y-despY));
  images[cur_frame_aux]->set_texture(render);
  images[cur_frame_aux]->draw(render, camera);

  ++cur_frame;
  //Cycle animation
  if (cur_frame / speed >= num_frames) {
    cur_frame = num_frame_return_cycle;
    _doCycle = true;
  }
}
