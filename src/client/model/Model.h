#ifndef TALLERZ_MODEL_H
#define TALLERZ_MODEL_H
class View;
#include "GameControllerProxy.h"
#include <client/view/Camera.h>
#include <common/Map/Map.h>
#include <client/view/View.h>
#include <common/IDs/TeamID.h>

class Model {
 private:
  Map &map;
  View &view;
  std::vector<UnitID> unitsSelected;
  GameControllerProxy &gameController;
  Camera &camera;
  PlayerID player;
  TeamID teamID;
  unsigned short unitSearchRange;
  unsigned short buildSearchRange;
  unsigned short terrainObjSearchRange;

 public:
  Model(Map &map,
        GameControllerProxy &gameController,
        Camera &camera,
        View &view,
        const PlayerID &player,
        const TeamID &teamID);
  GameControllerProxy *get_gameControllerProxy();
  void leftClick(int x, int y);
  PlayerID getPlayer() const;
  TeamID getTeamID() const;
  void rightClick(int x, int y);

  Map &getMap();

};

#endif //TALLERZ_MODEL_H
