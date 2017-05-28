#ifndef TALLERZ_GAMECOTROLLER_H
#define TALLERZ_GAMECOTROLLER_H

#include "Map.h"
#include "Unit.h"
#include "UnitID.h"
#include "BuildID.h"
#include "model/Events/Event.h"
#include "Bullet.h"
#include "Build.h"

class GameController {
 private:
  Map &map;
  std::map<UnitID, Unit *> units;
  std::vector<Bullet> bullets;
  std::vector<Unit *> deathUnits;
  std::map<BuildID, Build *> builds;
  void move(Unit *unit, std::vector<Event *> &events) const;
  void hunt(Unit *unit, std::vector<Event *> &events);
  void capture(Unit *unit, std::vector<Event *> &events) const;
  void unitReceiveDamage(Unit *current, std::vector<Event *> &events) const;
 public:
  GameController(Map &map, const std::map<UnitID, Unit *> &units);
  GameController(Map &map, const std::map<UnitID, Unit *> &units, const std::map<BuildID, Build *> &builds);
  void move(const UnitID &unit, const Position &position);
  void attack(const UnitID &attacker, const UnitID &attacked);
  void attack(const UnitID &attacker, const BuildID &attacked);
  void changeUnitFab(const BuildID &buildId, const UnitType &type);
  //void capture(UnitID unit, Position position);
  std::vector<Event *> tick();

  void doTick(std::vector<Event *> &events);
  void autoAttack(Unit *current);
  void unitsTick(std::vector<Event *> &events);
  void bulletsTick(std::vector<Event *> &vector);
  void buildsTick(std::vector<Event *> &events);
  void buildReceiveDamage(Build *pBuild, std::vector<Event *> &vector);
  ~GameController();
  void addUnits(std::vector<Unit *> vector, std::vector<Event *> &vector1);
};

#endif //TALLERZ_GAMECOTROLLER_H
