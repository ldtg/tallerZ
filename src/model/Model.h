#ifndef TALLERZ_MODEL_H
#define TALLERZ_MODEL_H

class GameController;

#include "Map.h"
#include "GameController.h"

class Model {
 private:
  Map &map;
  View &view;
  std::vector<UnitID> unitsSelected;
  GameController &gameController;
  Camera &camera;

 public:
  Model(Map &map, GameController& gameController, Camera &camera, View &view);
  void leftClick(int x, int y);
  void rightClick(int x, int y);
};

#endif //TALLERZ_MODEL_H
