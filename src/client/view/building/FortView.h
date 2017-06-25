#ifndef TALLERZ_CLIENTE_FORTVIEW_H
#define TALLERZ_CLIENTE_FORTVIEW_H

#include "BuildingView.h"
#include "client/view/Sprite.h"

class FortView : public BuildingView {
 private:
  Sprite *flag;
 public:
  FortView(const Position &pos, const std::string &color);
  ~FortView();
  void capture(const std::string &color);
  void destroyed();
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_FORTVIEW_H
