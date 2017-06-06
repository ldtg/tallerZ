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
  Generator generator(16,16,4,2,DUSTY,3,2);
  generator.set_water_lava_percentages(10,100);
  generator.territory_distribution_algorithm();
  generator.building_distribution_algorithm();
  generator.trace_paths();
  generator.trace_rivers();
  generator.set_rocks_percentages(10,100);
  generator.put_rocks();
  generator.put_vehicles();
  Store_map("mapa.json",generator)();
}