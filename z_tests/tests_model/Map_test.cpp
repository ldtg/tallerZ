
/*TEST(MapTest, getTile) {
  Tile tile_1(Position(50, 50), TerrainType::LAND, 1);
  Tile tile_2(Position(0, 150), TerrainType::LAND, 1);
  Tile tile_3(Position(150, 0), TerrainType::LAND, 1);
  Tile tile_4(Position(150, 150), TerrainType::LAND, 1);
  std::map<Position, Tile> stdmap;
  stdmap.emplace(Position(0, 0), tile_1);
  stdmap.emplace(Position(0, 1), tile_2);
  stdmap.emplace(Position(1, 0), tile_3);
  stdmap.emplace(Position(1, 1), tile_4);
  Map map(stdmap, 2, 2);
  ASSERT_TRUE(tile_3 == map.getTile(Position(150, 50)));
}

TEST(MapTest, getNeighbors) {
  Tile tile_1(Position(50, 50), TerrainType::LAND, 1);
  Tile tile_2(Position(50, 150), TerrainType::LAND, 1);
  Tile tile_3(Position(150, 50), TerrainType::LAND, 1);
  Tile tile_4(Position(150, 150), TerrainType::LAND, 1);
  std::map<Position, Tile> stdmap;
  stdmap.emplace(Position(0, 0), tile_1);
  stdmap.emplace(Position(0, 1), tile_2);
  stdmap.emplace(Position(1, 0), tile_3);
  stdmap.emplace(Position(1, 1), tile_4);
  Map map(stdmap, 2, 2);
  std::vector<Tile> neighbors = map.getNeighbors(tile_1);
  ASSERT_EQ(3, neighbors.size());
}*/