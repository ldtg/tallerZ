#include "gtest/gtest.h"
#include <map>
#include <Tile.h>
#include <Map.h>
TEST(MapTest, getTile) {
  Tile tile_1(Position(0, 0), TerrainType::LAND);
  Tile tile_2(Position(0, 1), TerrainType::LAND);
  Tile tile_3(Position(1, 0), TerrainType::LAND);
  Tile tile_4(Position(1, 1), TerrainType::LAND);
  std::map<Position, Tile> stdmap;
  stdmap.emplace(Position(0, 0), tile_1);
  stdmap.emplace(Position(0, 1), tile_2);
  stdmap.emplace(Position(1, 0), tile_3);
  stdmap.emplace(Position(1, 1), tile_4);
  Map map(stdmap, 2, 2);
  ASSERT_TRUE(tile_1 == map.getTile(Position(0, 0)));
}

TEST(MapTest, getNeighbors) {
  Tile tile_1(Position(0, 0), TerrainType::LAND);
  Tile tile_2(Position(0, 1), TerrainType::LAND);
  Tile tile_3(Position(1, 0), TerrainType::LAND);
  Tile tile_4(Position(1, 1), TerrainType::LAND);
  std::map<Position, Tile> stdmap;
  stdmap.emplace(Position(0, 0), tile_1);
  stdmap.emplace(Position(0, 1), tile_2);
  stdmap.emplace(Position(1, 0), tile_3);
  stdmap.emplace(Position(1, 1), tile_4);
  Map map(stdmap, 2, 2);
  std::vector<Tile> neighbors = map.getNeighbors(tile_1);
  ASSERT_EQ(3, neighbors.size());
}