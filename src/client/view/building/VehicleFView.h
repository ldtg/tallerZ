#ifndef TALLERZ_CLIENTE_VEHICLEFVIEW_H
#define TALLERZ_CLIENTE_VEHICLEFVIEW_H

#include "BuildingView.h"
#include "client/view/Sprite.h"

class VehicleFView : public BuildingView {
 private:
  Sprite *vehicle;
  Sprite *spin;
  Sprite *smoke;
  Sprite *vent;
  Sprite *bulb;
  Image *levelFactory;
  Image *layoutColor;

 public:
  VehicleFView(const Position &pos, const std::string &color);
  ~VehicleFView();
  void capture(const std::string &color);
  void destroyed();
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_VEHICLEFVIEW_H
