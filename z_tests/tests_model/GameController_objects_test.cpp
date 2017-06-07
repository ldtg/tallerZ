/*#include <model/Build.h>
#include <model/Events/Event.h>
#include <model/Data.h>
#include <chrono>
#include <model/UnitFactory.h>
#include <model/GaiaPlayer.h>
#include "gtest/gtest.h"
#include "Map.h"

class GameController_objects_test : public ::testing::Test {
 public:
  Map map;
  Player playerA;
  Team teamA;
  Player playerB;
  Team teamB;
  GaiaPlayer gaia;
  Build *build;
  Unit *unit;
  TerrainObject *bridge;
  TerrainObject *rock;
  std::map<UnitID, Unit *> units;
  std::map<BuildID, Build *> builds;
  std::map<CapturableID, Capturable *> capturables;
  std::map<TerrainObjectID, TerrainObject> terrainObjects;
  std::vector<Event *> events;
  GameController_objects_test()
      : playerA(PlayerColor::RED), playerB(PlayerColor::BLUE) {
    std::map<Position, Tile> stdmap;
    stdmap.emplace(Position(0, 0), Tile(Position(50, 50), data.land));
    stdmap.emplace(Position(1, 0), Tile(Position(150, 50), data.land));
    stdmap.emplace(Position(2, 0), Tile(Position(250, 50), data.land));

    stdmap.emplace(Position(0, 1), Tile(Position(50, 150), data.road));
    stdmap.emplace(Position(1, 1), Tile(Position(150, 150), data.lava));
    stdmap.emplace(Position(2, 1),
                   Tile(Position(250, 150), data.asphaltedBridgeTerrain));

    stdmap.emplace(Position(0, 2), Tile(Position(50, 250), data.land));
    stdmap.emplace(Position(1, 2), Tile(Position(150, 250), data.land));
    stdmap.emplace(Position(2, 2), Tile(Position(250, 250), data.land));

    playerA.addTerritory();
    playerB.addTerritory();
    teamA.addPlayer(&playerA);
    teamB.addPlayer(&playerB);

    bridge =
        new TerrainObject(data.asphaltedBridgeObject, Position(250, 150), &gaia);
    rock = new TerrainObject(data.rockObject, Position(50, 150), &gaia);
    terrainObjects.emplace(bridge->getID(), *bridge);
    terrainObjects.emplace(rock->getID(), *rock);

    std::map<TerrainObjectID, TerrainObjectState> tomap;
    tomap.emplace(bridge->getID(), bridge->getState());
    tomap.emplace(rock->getID(), rock->getState());
    std::map<BuildID, BuildState> buildmap;

    unit = UnitFactory::createToughDynamic(Position(50, 50), playerB, teamB);
    units.emplace(unit->getId(), unit);

    map = Map(stdmap, buildmap, tomap, 3, 3);
    map.addUnit(unit->getId(), unit->getUnitState());

  }
  void SetUp() {

  }
  void TearDown() {

  }
  ~GameController_objects_test() {
    for (Event *event:events) {
      delete (event);
    }
  }

};

TEST_F(GameController_objects_test, bridge_move) {
  GameController gc(map, units, builds, capturables, terrainObjects);
  gc.move(unit->getId(), Position(250, 250));
  while (unit->isMoving()) {
    auto aux = gc.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  ASSERT_EQ(unit->getCenterPosition(), Position(250, 250));
}
TEST_F(GameController_objects_test, rock_destroy) {
  GameController gc(map, units, builds, capturables, terrainObjects);
  gc.attack(unit->getId(), rock->getID());
  while (!unit->isStill()) {
    auto aux = gc.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  ASSERT_TRUE(unit->isStill());
}
TEST_F(GameController_objects_test, bridge_destroy) {
  GameController gc(map, units, builds, capturables, terrainObjects);
  gc.attack(unit->getId(), bridge->getID());
  while (!unit->isStill()) {
    auto aux = gc.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  ASSERT_TRUE(unit->isStill());
}*/