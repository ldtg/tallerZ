#include <model/Build.h>
#include <model/Events/Event.h>
#include <model/Data.h>
#include <chrono>
#include <model/UnitFactory.h>
#include "gtest/gtest.h"
#include "Map.h"

class GameController_build_test : public ::testing::Test {
 public:
  Map map;
  Player playerA;
  Team teamA;
  Player playerB;
  Team teamB;
  Build *build;
  Unit *unit;
  std::map<UnitID, Unit *> units;
  std::map<BuildID, Build *> builds;
  std::vector<Event *> events;
  GameController_build_test() : playerA(PlayerColor::RED), playerB(PlayerColor::BLUE) {

    std::map<Position, Tile> stdmap;
    stdmap.emplace(Position(0, 0), Tile(Position(50, 50), data.land));
    stdmap.emplace(Position(1, 0), Tile(Position(150, 50), data.land));
    stdmap.emplace(Position(2, 0), Tile(Position(250, 50), data.land));

    stdmap.emplace(Position(0, 1), Tile(Position(50, 150), data.land));
    stdmap.emplace(Position(1, 1), Tile(Position(150, 150), data.lava));
    stdmap.emplace(Position(2, 1), Tile(Position(250, 150), data.land));

    stdmap.emplace(Position(0, 2), Tile(Position(50, 250), data.land));
    stdmap.emplace(Position(1, 2), Tile(Position(150, 250), data.land));
    stdmap.emplace(Position(2, 2), Tile(Position(250, 250), data.land));

    playerA.addTerritory();
    playerB.addTerritory();
    teamA.addPlayer(&playerA);
    teamB.addPlayer(&playerB);

    build = new Build(data.fort, Position(50, 250), playerA, teamA, 3);
    builds.emplace(build->getId(), build);
    std::map<BuildID, BuildState> buildmap;
    buildmap.emplace(build->getId(), build->getBuildState());

    unit = UnitFactory::createToughDynamic(Position(50, 104), playerB, teamB);
    units.emplace(unit->getId(), unit);

    map = Map(stdmap, buildmap, 3, 3);
    map.addUnit(unit->getId(), unit->getUnitState());

  }
  void SetUp() {

  }
  void TearDown() {

  }
  ~GameController_build_test(){
    for (Event *event:events) {
      delete (event);
    }
  }

};
TEST_F(GameController_build_test,
       DISABLED_build_create) { // DISABLED porque tarda mucho con los valores default del juego ~9:35
  GameController gc(map, units, builds);
  auto begin = std::chrono::high_resolution_clock::now();
  gc.changeUnitFab(build->getId(), UnitType::R_TOUGH);
  while (!build->hasToBuild()) {
    auto aux = gc.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  events = gc.tick();
  auto end = std::chrono::high_resolution_clock::now();
  auto diff =
      std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
  std::cerr << diff.count() << std::endl;
  ASSERT_TRUE(std::abs(diff.count()
                           - data.getData(build->getActualUnitFab()).factoryBaseTimeInSec)
                  < 1);
  ASSERT_EQ(data.getData(build->getActualUnitFab()).factoryRate, events.size());
}
TEST_F(GameController_build_test, build_attack_pos) {
  Position attackPos = build->getAttackPosition(Position(50, 150));
  ASSERT_EQ(attackPos, Position(50, 100));
}
TEST_F(GameController_build_test, build_attack_destroy) {
  GameController gc(map, units, builds);
  auto begin = std::chrono::high_resolution_clock::now();
  gc.attack(unit->getId(), build->getId());
  while (build->isAlive()) {
    auto aux = gc.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto diff =
      std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
  std::cerr << diff.count() << std::endl;
  ASSERT_TRUE(diff.count() > 20);
}