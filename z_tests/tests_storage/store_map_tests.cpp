//
// Created by darius on 09/05/17.
//

#include "map_generation/Generator.h"
#include "../../src/storage/Store_map.h"
#include "Map_Loader.h"
#include "json.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using json = nlohmann::json;

TEST(store_map_tests, Store_map){
  Generator generator(12,12,9,3,DUSTY,0,2);
  generator.set_water_lava_percentages(0,0);
  generator.territory_distribution_algorithm();
  generator.building_distribution_algorithm();
  generator.trace_paths();
  generator.trace_rivers();
  generator.set_rocks_percentages(0,0);
  generator.put_rocks();
  //generator.put_vehicles();
  Store_map("mapa.json",generator)();

  //std::cerr << std::setw(4) << store_map.get_json() << '\n';
}

TEST(load_map_tests, Map_Loader){
  Map_Loader map_loader("mapa.json");
  map_loader.load_file();
  std::cout << map_loader.get_json()["100"]["territory"] << '\n';

  //std::cerr << std::setw(4) << map_loader.get_json() << '\n';
}

TEST(center_position_test, Map_Loader){
  Map_Loader map_loader("mapa.json");
  Position pos = map_loader.centered_position(10,10);
  std::cout << pos.getX() << '\n';
  std::cout << pos.getY() << '\n';
}

TEST(read_data_test, Map_Loader){
  Map_Loader map_loader("mapa.json");
  map_loader.load_file();
  Position_Data data = map_loader.read_data(868);
  ASSERT_TRUE(data.x == 28);
  ASSERT_TRUE(data.y == 21);
  ASSERT_TRUE(data.vehicle_factory == false);
  ASSERT_TRUE(data.bridge == false);
  ASSERT_TRUE(data.vehicle == false);
  ASSERT_TRUE(data.territory == 3);
  ASSERT_TRUE(data.terrain_type == 0);
  ASSERT_TRUE(data.rock == false);
  ASSERT_TRUE(data.robot_factory == false);
  ASSERT_TRUE(data.fort == false);
  ASSERT_TRUE(data.flag == false);
}

TEST(set_players_test, Map_Loader){
  Map_Loader map_loader("mapa.json");
  map_loader.load_file();
  map_loader.load_configuration();
  map_loader.set_players();

}