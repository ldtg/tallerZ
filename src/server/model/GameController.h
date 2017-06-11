#ifndef TALLERZ_GAMECOTROLLER_H
#define TALLERZ_GAMECOTROLLER_H

#include <server/model/Events/serverEvent.h>
#include "common/Map/Map.h"
#include "Unit.h"
#include "common/IDs/UnitID.h"
#include "common/IDs/BuildID.h"
#include "client/model/Events/Event.h"
#include "Bullet.h"
#include "Build.h"
#include "Capturable.h"
#include "TerrainObject.h"

class GameController {
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
  std::queue<serverEvent*> &eventQueue;
  void move(Unit *unit,
            std::vector<Event *> &events,
            std::map<UnitID, Unit *>::iterator &it);
  void hunt(Unit *unit,
            std::vector<Event *> &events,
            std::map<UnitID, Unit *>::iterator &it);
  void capture(Unit *unit,
               std::vector<Event *> &events,
               std::map<UnitID, Unit *>::iterator &it);
  void autoAttack(Unit *current,
                  std::vector<Event *> &events,
                  std::map<UnitID, Unit *>::iterator &it);
  void unitReceiveDamage(Unit *current, std::vector<Event *> &events) const;

  void doTick(std::vector<Event *> &events);
  void unitsTick(std::vector<Event *> &events);
  void bulletsTick(std::vector<Event *> &vector);
  void buildsTick(std::vector<Event *> &events);
  void buildReceiveDamage(Build *pBuild, std::vector<Event *> &vector);
  void addUnits(std::vector<Unit *> vector, std::vector<Event *> &vector1);
  void PlayersTick(std::vector<Event *> &vector);
  void TeamsTick(std::vector<Event *> &events);
  void objectsTick(std::vector<Event *> &events);

 public:
  GameController(
      Map &map,
      const std::map<UnitID, Unit *> &units,
      const std::map<BuildID, Build *> &builds,
      const std::map<CapturableID, Capturable *> &capturables,
      const std::map<TerrainObjectID, TerrainObject> &terrainObjects,
      const std::map<PlayerID, Player *> &players,
      const std::map<TeamID, Team> &teams,
      std::queue<serverEvent*> &eventQueue

  );
  virtual void move(const UnitID &unit, const Position &position);
  virtual void attack(const UnitID &attacker, const UnitID &attacked);
  virtual void attack(const UnitID &attacker, const BuildID &attacked);
  virtual void attack(const UnitID &attacker, const TerrainObjectID &attacked);
  virtual void changeUnitFab(const BuildID &buildId, const UnitType &type);
  virtual void capture(const UnitID &unit, const CapturableID &capturable);
  virtual std::vector<Event *> tick();

  ~GameController();
};

#endif //TALLERZ_GAMECOTROLLER_H
