#ifndef TALLERZ_CLIENTE_BUILDVIEW_H
#define TALLERZ_CLIENTE_BUILDVIEW_H

#include <SDL_render.h>
#include <common/Types/BuildType.h>
#include "client/view/Camera.h"
#include "client/view/Image.h"
#include "client/view/Sprite.h"

#define BUILDWIDHT 100
#define BUILDHEIGHT 100

class BuildingView {
 protected:
  Image *building;
  BuildType type;
  Position pos;
  std::string color;
  std::vector<Sprite*> deathEffects;

  BuildingView(const BuildType &type, const Position &pos,
               const std::string &color);

 public:
  virtual ~BuildingView();
  virtual void capture(const std::string &color) = 0;
  virtual void destroyed();
  virtual void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_BUILDVIEW_H
