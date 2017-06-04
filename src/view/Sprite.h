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
  int num_frame_return_cycle;
  std::string filename;
  bool _doCycle;
  std::string color;

 public:
  Sprite();
  Sprite(const char *file, int num_frames, int speed,
         int num_frame_return_cycle, std::string color="");
  virtual ~Sprite();
  bool doCycle() const;
  std::string getColor() const;
  void set_texture(SDL_Renderer *render);
  virtual void draw(SDL_Renderer *render, Camera &camera);
};

#endif //SPRITE_H
