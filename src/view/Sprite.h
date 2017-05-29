#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"
#include <string>
#include "ObjectMapaVista.h"

class Sprite : public ObjectMapaVista {
 protected:
  int num_frames;
  int cur_frame;
  int speed;
//        int x;
//        int y;
  std::string filename;
 public:
  Sprite();
  Sprite(const char *file, int num_frames, int speed);
  virtual ~Sprite();
  void set_texture(SDL_Renderer *render);
  void draw(SDL_Renderer *render);
};

#endif //SPRITE_H
