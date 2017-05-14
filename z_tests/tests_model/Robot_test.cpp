#include <Robot.h>

#include "gtest/gtest.h"

TEST(RobotTest, create) {
  Position pos0(0, 0);
  Robot robot(pos0, UnitType::R_GRUNT);
  ASSERT_TRUE(robot.isAlive());
  ASSERT_TRUE(robot.isStill());
  ASSERT_EQ(pos0, robot.getCurrentPosition());
}
TEST(RobotTest, move) {
  Position pos0(0, 0);
  Robot robot(pos0, UnitType::R_GRUNT);
  std::queue<Movement> moves;
  moves.push(Movement::RIGHT);
  moves.push(Movement::LEFT);
  moves.push(Movement::URIGHT);
  robot.move(moves);
  ASSERT_TRUE(robot.isMoving());
  robot.doMove();
  ASSERT_EQ(Position(1, 0), robot.getCurrentPosition());
  robot.doMove();
  ASSERT_EQ(Position(0, 0), robot.getCurrentPosition());
  robot.doMove();
  ASSERT_EQ(Position(1, 1), robot.getCurrentPosition());
}
TEST(RobotTest, attack) {
  Position pos0(0, 0);
  Position pos1(1, 1);
  Robot attacker(pos0, UnitType::R_GRUNT);
  Robot attacked(pos1, UnitType::R_GRUNT);
  attacker.attack(&attacked);
  attacked.receiveDamages();
  ASSERT_EQ(50, attacked.getHealth());
  attacker.attack(&attacked);
  attacker.attack(&attacked);
  attacker.attack(&attacked);
  attacker.attack(&attacked);
  attacker.attack(&attacked);
  attacked.receiveDamages();
  ASSERT_TRUE(!attacked.isAlive());
}