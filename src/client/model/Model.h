#ifndef TALLERZ_MODEL_H
#define TALLERZ_MODEL_H

#include <client/view/Camera.h>
#include <common/Map/Map.h>
#include <client/view/View.h>
#include "GameControllerProxy.h"

class Model {
 private:
  Map &map;
  View &view;
  std::vector<UnitID> unitsSelected;
  GameControllerProxy &gameController;
  Camera &camera;

 public:
  Model(Map &map, GameControllerProxy& gameController, Camera &camera, View &view);
  GameControllerProxy * get_gameControllerProxy(){
    return &gameController;
  }
  void leftClick(int x, int y);
  void rightClick(int x, int y);

};

#endif //TALLERZ_MODEL_H
