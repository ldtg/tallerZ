#include <Robot.h>
#include <RobotFactory.h>

#include "gtest/gtest.h"

TEST(RobotTest, create) {
  Robot grunt = RobotFactory::createGrunt(Position(0, 0));
  ASSERT_TRUE(grunt.isAlive());
}
TEST(RobotTest, move) {
  
}
TEST(RobotTest, attack) {

}