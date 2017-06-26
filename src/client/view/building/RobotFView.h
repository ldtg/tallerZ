#ifndef TALLERZ_CLIENTE_ROBOTFVIEW_H
#define TALLERZ_CLIENTE_ROBOTFVIEW_H

#include "BuildingView.h"
#include "client/view/Sprite.h"

class RobotFView : public BuildingView {
 private:
  Sprite *robot;
  Sprite *spin;
  Sprite *smoke;
  Sprite *box;
  Image *levelFactory;
  Image *layoutColor;

 public:
  RobotFView(const std::string &techLevel,
             const Position &pos,
             const std::string &color);
  ~RobotFView();
  void capture(const std::string &color);
  void destroyed();
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_ROBOTFVIEW_H
