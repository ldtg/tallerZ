#include "gtest/gtest.h"
#include <Data.h>
#include <Tile.h>
#include <Map.h>
#include <UnitFactory.h>
#include <chrono>
#include <model/CapturableVehicle.h>
#include <model/Territory.h>
#include "GameController.h"

class GameControllerCapturables_test : public ::testing::Test {

 public:
  Map map;
  Player playerA;
  Player gaia;
  Build *build;
  Team teamA;
  std::map<UnitID, Unit *> units;

  std::map<Position, Capturable *> capturables;
  std::map<BuildID, Build *> builds;
  Robot *robotA;
  Vehicle *jeepA;
  std::vector<Event *> events;
  GameControllerCapturables_test() : playerA("A"), gaia("gaia") {
  }

  void SetUp() {
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

    teamA.addPlayer(&playerA);
    teamA.addPlayer(&gaia);
    build = new Build(data.fort, Position(50, 50), playerA, teamA, 3);
    builds.emplace(build->getId(), build);
    std::map<BuildID, BuildState> buildmap;
    buildmap.emplace(build->getId(), build->getBuildState());

    map = Map(stdmap, buildmap, 3, 3);
    robotA = UnitFactory::createGruntDynamic(Position(50, 50), playerA, teamA);
    jeepA = UnitFactory::createJeepDynamic(Position(150, 50), gaia, teamA);
    playerA.addUnit();
    Capturable *capturable = new CapturableVehicle(*jeepA);
    std::vector<Build *> buildsT;
    buildsT.push_back(build);
    Capturable
        *terrain = new Territory(Position(50, 250), buildsT, gaia, teamA);
    capturables.emplace(capturable->getCapturePosition(), capturable);
    capturables.emplace(terrain->getCapturePosition(), terrain);
    units.emplace(robotA->getId(), robotA);
    units.emplace(jeepA->getId(), jeepA);
    map.addUnit(robotA->getId(), robotA->getUnitState());
    map.addUnit(jeepA->getId(), jeepA->getUnitState());
  }

  void TearDown() {
    for (Event *event:events) {
      delete (event);
    }
  }

  ~GameControllerCapturables_test() {

  }
};
TEST_F(GameControllerCapturables_test, capture) {
  std::vector<Event *> aux;
  GameController gameController(map, units, builds, capturables);
  gameController.capture(robotA->getId(), jeepA->getCurrentPosition());
  while (robotA->isCapturing()) {
    aux = gameController.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  aux = gameController.tick();
  events.insert(events.end(), aux.begin(), aux.end());
  ASSERT_TRUE(robotA->isStill());
}
TEST_F(GameControllerCapturables_test, capture_terrain) {
  std::vector<Event *> aux;
  GameController gameController(map, units, builds, capturables);
  gameController.capture(robotA->getId(), Position(50,250));
  while (robotA->isCapturing()) {
    aux = gameController.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  ASSERT_TRUE(robotA->isStill());
}