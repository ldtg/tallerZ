#ifndef TALLERZ_REALGAMECONTROLLER_H
#define TALLERZ_REALGAMECONTROLLER_H

#include <common/Map/Map.h>
#include <server/model/Events/serverEvent.h>
#include <server/serverGameController.h>
#include <storage/Game_Loader.h>
#include <common/Queue/Queue.h>
#include "Unit.h"
#include "TerrainObject.h"
#include "Build.h"
class realGameController : public serverGameController{
 private:
  Map &map;
  std::map<UnitID, Unit *> units;
  std::vector<Bullet> bullets;
  std::map<BuildID, Build *> builds;
  std::map<CapturableID, Capturable *> capturables;
  std::map<PlayerID, Player *> players;
  std::map<TeamID, Team> teams;
  std::map<TerrainObjectID, TerrainObject> terrainObjects;
  std::vector<Unit *> deathUnits;

  Queue<serverEvent*> &eventQueue;
  void move(Unit *unit, std::map<UnitID, Unit *>::iterator &it);
  void hunt(Unit *unit, std::map<UnitID, Unit *>::iterator &it);
  void capture(Unit *unit, std::map<UnitID, Unit *>::iterator &it);
  void autoAttack(Unit *current, std::map<UnitID, Unit *>::iterator &it);
  void unitReceiveDamage(Unit *current) const;

  void doTick();
  void unitsTick();
  void bulletsTick();
  void buildsTick();
  void buildReceiveDamage(Build *pBuild);
  void addUnits(std::vector<Unit *> vector);
  void playersTick();
  void teamsTick();
  void objectsTick();
 public:
  realGameController(Map &map,const Game_Loader &game_loader,Queue<serverEvent*> &evqueue);
  virtual void move(const UnitID &unit, const Position &position) override;
  virtual void attack(const UnitID &attacker, const UnitID &attacked) override;
  virtual void attack(const UnitID &attacker, const BuildID &attacked) override;
  virtual void attack(const UnitID &attacker, const TerrainObjectID &attacked) override;
  virtual void changeUnitFab(const BuildID &buildId, const UnitType &type) override;
  virtual void capture(const UnitID &unit, const CapturableID &capturable) override;
  virtual void tick();
  virtual void playerDisconnected(const PlayerID player);
  virtual ~realGameController();
};

#endif //TALLERZ_REALGAMECONTROLLER_H
