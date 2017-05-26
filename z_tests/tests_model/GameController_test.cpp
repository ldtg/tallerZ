#include "gtest/gtest.h"
#include <Data.h>
#include <Tile.h>
#include <Map.h>
#include <UnitFactory.h>
#include <chrono>
#include "GameController.h"


extern Data data;

class GameController_test : public ::testing::Test {

 public:
  Map map;
  std::map<UnitID, Unit *> units;
  Unit *robotA;
  Unit *robotB;
  Unit *robotC;
  Unit *jeepA;
  std::vector<Event *> events;
  GameController_test() {
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

    map = Map(stdmap, 3, 3);
    robotA = UnitFactory::createGruntDynamic(Position(50, 50));
    units.emplace(robotA->getId(), robotA);
    robotB = UnitFactory::createGruntDynamic(Position(250, 245));
    units.emplace(robotB->getId(), robotB);
    robotC = UnitFactory::createGruntDynamic(Position(250, 250));
    units.emplace(robotC->getId(), robotC);
    jeepA = UnitFactory::createJeepDynamic(Position(150, 255));
    units.emplace(jeepA->getId(), jeepA);
  }

  void TearDown() {
    for (auto &par : units) {
      delete (par.second);
    }
    for (auto &event : events) {
      delete event;
    }
  }

  ~GameController_test() {

  }
};
TEST_F(GameController_test, move) {
  std::vector<Event *> aux;
  GameController gameController(map, units);
  gameController.move(robotA->getId(), Position(90, 50));
  while (robotA->isMoving()) {
    aux = gameController.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  ASSERT_TRUE(robotA->isStill());
}
TEST_F(GameController_test, robotAttack) {
  std::vector<Event *> aux;
  GameController gameController(map, units);
  gameController.attack(robotA->getId(), robotB->getId());
  while (robotA->isHunting()) {
    aux = gameController.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  ASSERT_TRUE(!robotB->isAlive());
}


 TEST_F(GameController_test, unitAutoAttack) {
  std::vector<Event *> aux;
  GameController gameController(map, units);
  while (robotC->isAlive()) {
    aux = gameController.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  ASSERT_TRUE(!robotC->isAlive() && jeepA->isAlive() && robotA->isAlive()
                  && !robotB->isAlive());
}

TEST_F(GameController_test, time) {
  std::vector<Event *> aux;
  GameController gameController(map, units);
  gameController.move(robotA->getId(), Position(250, 250));
  std::chrono::duration<double> diff;
  unsigned short count = 0;
  auto begin = std::chrono::high_resolution_clock::now();
  while (diff.count() < 1) {
    aux = gameController.tick();
    events.insert(events.end(), aux.begin(), aux.end());
    auto end = std::chrono::high_resolution_clock::now();
    diff =
        std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
    count++;
  }
  ASSERT_TRUE(std::abs(count - data.ticksPerSec) < 5);
}
TEST_F(GameController_test, timed_robot_attack) {
  std::vector<Event *> aux;
  GameController gameController(map, units);
  gameController.attack(robotB->getId(), robotC->getId());
  std::chrono::duration<double> diff;
  auto begin = std::chrono::high_resolution_clock::now();
  while (robotC->isAlive()) {
    aux = gameController.tick();
    events.insert(events.end(), aux.begin(), aux.end());
  }
  auto end = std::chrono::high_resolution_clock::now();
  diff =
      std::chrono::duration_cast<std::chrono::duration<double>>(end - begin);
  double diffScs = diff.count();
  ASSERT_TRUE(std::abs(diffScs - 15) < 2);
}

