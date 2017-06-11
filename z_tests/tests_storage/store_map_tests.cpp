//
// Created by darius on 09/05/17.
//

#include "map_generation/Generator.h"
#include "../../src/storage/Store_map.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using json = nlohmann::json;

TEST(store_map_tests, Store_map){
  Generator generator(20,20,9,2,WINTER,3,2);
  generator.set_water_lava_percentages(10,80);
  generator.territory_distribution_algorithm();
  generator.building_distribution_algorithm();
  generator.trace_paths();
  generator.trace_rivers();
  generator.set_rocks_percentages(10,50);
  generator.put_rocks();
  //generator.put_vehicles();
  Store_map("mapa.json",generator)();
}