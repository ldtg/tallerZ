#ifndef TALLERZ_CLIENTE_VEHICLEVIEW_H
#define TALLERZ_CLIENTE_VEHICLEVIEW_H

#include "UnitView.h"

class VehicleView : public UnitView {
 private:
  Sprite *top;
 public:
  VehicleView(UnitType type, std::string &color, Position pos,
              std::string &action, std::string &rotation);
  ~VehicleView();
  void walk(int rotation, const Position &posTo);
  void still();
  void fire(const Position &huntedPos);
  void draw(SDL_Renderer *render, Camera &camera);
};

#endif //TALLERZ_CLIENTE_VEHICLEVIEW_H
