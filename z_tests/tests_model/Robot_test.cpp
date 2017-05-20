#include <Robot.h>
#include <UnitFactory.h>

#include "gtest/gtest.h"

TEST(RobotTest, create) {
  Robot grunt = UnitFactory::createGrunt(Position(0, 0));
  ASSERT_TRUE(grunt.isAlive());
}
TEST(RobotTest, move) {

}
TEST(RobotTest, attack) {

}