#include <Map.h>
#include <Robot.h>
#include <AStar.h>
#include "gtest/gtest.h"

class AStar_test : public ::testing::Test {
 public:
  Map map;
  AStar_test() {
    // initialization code here
    std::map<Position, Tile> stdmap;
    stdmap.emplace(Position(0, 0), Tile(Position(0, 0), TerrainType::LAND));
    stdmap.emplace(Position(1, 0), Tile(Position(1, 0), TerrainType::LAVA));
    stdmap.emplace(Position(2, 0), Tile(Position(2, 0), TerrainType::LAVA));

    stdmap.emplace(Position(0, 1), Tile(Position(0, 1), TerrainType::LAND));
    stdmap.emplace(Position(1, 1), Tile(Position(1, 1), TerrainType::LAVA));
    stdmap.emplace(Position(2, 1), Tile(Position(2, 1), TerrainType::LAVA));

    stdmap.emplace(Position(0, 2), Tile(Position(0, 2), TerrainType::LAND));
    stdmap.emplace(Position(1, 2), Tile(Position(1, 2), TerrainType::LAND));
    stdmap.emplace(Position(2, 2), Tile(Position(2, 2), TerrainType::LAND));

    map = Map(stdmap, 3, 3);
  }

  void SetUp() {
    // code here will execute just before the test ensues
  }

  void TearDown() {
    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
  }

  ~AStar_test() {
    // cleanup any pending stuff, but no exceptions allowed
  }

  // put in any custom data members that you need
};
TEST_F(AStar_test, find) {
  Position ipos(0,0);
  Position epos(2,2);
  Robot robot(ipos, UnitType::R_GRUNT);
  AStar astar(map, &robot, epos);
  std::queue<Movement> path = astar.find();
  robot.move(path);
  while(robot.isMoving()) {
    robot.doMove();
  }
  ASSERT_EQ(epos, robot.getCurrentPosition());
}