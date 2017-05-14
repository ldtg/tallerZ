#include <Tile.h>
#include "gtest/gtest.h"

TEST(TileTest, IsEmpty) {
  Tile tile(Position(0, 0), TerrainType::LAND);
  ASSERT_TRUE(tile.isEmpty());
}