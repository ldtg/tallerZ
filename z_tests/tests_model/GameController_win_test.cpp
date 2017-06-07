/*#include <model/Build.h>
#include <model/Events/Event.h>
#include <model/Data.h>
#include <chrono>
#include <model/UnitFactory.h>
#include <model/GaiaPlayer.h>
#include "gtest/gtest.h"
#include "Map.h"

class GameController_win_test : public ::testing::Test {
 public:
  Map map;
  Player playerA;
  Team teamA;
  Player playerB;
  Team teamB;
  GaiaPlayer gaia;
  Build *build;
  Unit *unitA;
  Unit *unitB;
  std::map<UnitID, Unit *> units;
  std::map<BuildID, Build *> builds;
  std::map<CapturableID, Capturable *> capturables;
  std::map<TerrainObjectID, TerrainObject> terrainObjects;
  std::vector<Event *> events;
  std::map<PlayerID, Player *> players;
  std::map<TeamID, Team> teams;
  GameController_win_test()
      : playerA(PlayerColor::RED), playerB(PlayerColor::BLUE) {
    std::map<Position, Tile> stdmap;
    stdmap.emplace(Position(0, 0), Tile(Position(50, 50), data.land));
    stdmap.emplace(Position(1, 0), Tile(Position(150, 50), data.land));
    stdmap.emplace(Position(2, 0), Tile(Position(250, 50), data.land));

    stdmap.emplace(Position(0, 1), Tile(Position(50, 150), data.road));
    stdmap.emplace(Position(1, 1), Tile(Position(150, 150), data.lava));
    stdmap.emplace(Position(2, 1),
                   Tile(Position(250, 150), data.land));

    stdmap.emplace(Position(0, 2), Tile(Position(50, 250), data.land));
    stdmap.emplace(Position(1, 2), Tile(Position(150, 250), data.land));
    stdmap.emplace(Position(2, 2), Tile(Position(250, 250), data.land));

    playerA.addTerritory();
    playerA.addUnit();
    playerB.addTerritory();
    playerB.addUnit();
    teamA.addPlayer(&playerA);
    teamB.addPlayer(&playerB);
    players.emplace(playerA.getID(), &playerA);
    players.emplace(playerB.getID(), &playerB);
    teams.emplace(teamA.getID(), teamA);
    teams.emplace(teamB.getID(), teamB);
    std::map<TerrainObjectID, TerrainObjectState> tomap;

    build = new Build(data.fort, Position(50, 250), playerA, teamA, 3);
    builds.emplace(build->getId(), build);
    std::map<BuildID, BuildState> buildmap;
    buildmap.emplace(build->getId(), build->getBuildState());

    unitA = UnitFactory::createGruntDynamic(Position(50, 50), playerA, teamA);
    unitB = UnitFactory::createGruntDynamic(Position(60, 60), playerB, teamB);
    units.emplace(unitA->getId(), unitA);
    units.emplace(unitB->getId(), unitB);

    map = Map(stdmap, buildmap, tomap, 3, 3);
    map.addUnit(unitA->getId(), unitA->getUnitState());
    map.addUnit(unitB->getId(), unitB->getUnitState());

  }
  void SetUp() {

  }
  void TearDown() {
    for (Event *event:events) {
      delete (event);
    }
  }
  ~GameController_win_test() {

  }

};

TEST_F(GameController_win_test, out_of_robots_test) {
  GameController
      gc(map, units, builds, capturables, terrainObjects, players, teams);
  gc.attack(unitA->getId(), unitB->getId());
  while (playerB.isAlive()) {
    auto aux = gc.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  ASSERT_FALSE(playerB.isAlive());

}
TEST_F(GameController_win_test, fort_end_test) {
  GameController
      gc(map, units, builds, capturables, terrainObjects, players, teams);
  gc.attack(unitB->getId(), build->getId());
  while (playerA.isAlive()) {
    auto aux = gc.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  ASSERT_FALSE(playerA.isAlive());

}*/