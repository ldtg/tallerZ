#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"
#include <string>
#include "ObjectView.h"
#include "Image.h"

class Sprite : public ObjectView {
 protected:
  int num_frames;
  int cur_frame;
  int speed;
  int num_frame_return_cycle;
  std::string filename;
  int despX;
  int despY;
  bool _doCycle;
  std::string color;
  std::vector<Image*> images;

 public:
  Sprite(const char *file, int num_frames, int speed,
         int num_frame_return_cycle, std::string color="",
         int despX=0, int despY=0);
  virtual ~Sprite();

  bool doCycle() const;
  std::string getColor() const;
  ViewPosition getDrawPosition() const;
  void setRotation(double rotation);
  int getCurFrame() const;
  void setDesp(const int despX, const int despY);
  void set_texture(SDL_Renderer *render);
  void scale(float scaleW, float scaleH);
  virtual void draw(SDL_Renderer *render, Camera &camera);
};

#endif //SPRITE_H
