//
// Created by darius on 05/06/17.
//

#include "map_generation/Generator.h"
#include "../../src/storage/Store_map.h"
#include "Game_Loader.h"
#include "json.hpp"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

//TEST(load_map_tests, Game_Loader){
//  Game_Loader map_loader("mapa.json");
//  map_loader.load_file();
//  std::cout << map_loader.get_json()["100"]["territory"] << '\n';
//
//  //std::cerr << std::setw(4) << map_loader.get_json() << '\n';
//}

//TEST(center_position_test, Game_Loader){
//  Game_Loader map_loader("mapa.json");
//  Position pos = map_loader.centered_position(10,10);
//  std::cout << pos.getX() << '\n';
//  std::cout << pos.getY() << '\n';
//}

//TEST(read_data_test, Game_Loader){
//  Game_Loader map_loader("mapa.json");
//  map_loader.load_file();
//  Position_Data data = map_loader.read_data(868);
//  ASSERT_TRUE(data.x == 28);
//  ASSERT_TRUE(data.y == 21);
//  ASSERT_TRUE(data.vehicle_factory == false);
//  ASSERT_TRUE(data.bridge == false);
//  ASSERT_TRUE(data.vehicle == false);
//  ASSERT_TRUE(data.territory == 3);
//  ASSERT_TRUE(data.terrain_type == 0);
//  ASSERT_TRUE(data.rock == false);
//  ASSERT_TRUE(data.robot_factory == false);
//  ASSERT_TRUE(data.fort == false);
//  ASSERT_TRUE(data.flag == false);
//}

//TEST(set_players_test, Game_Loader){
//  Game_Loader map_loader("mapa.json");
//  map_loader.load_file();
//  map_loader.load_configuration();
//  map_loader.set_players();
//}

TEST(run_test, Map_Loader){
  Game_Loader map_loader("mapa.json");
  Map map1 = map_loader.run();
  std::cout << "Capturables\n";
  for (const auto& i: map_loader.get_capturables()){
    std::cout << i.second.ownerID.getColor() << std::endl;
  }

  BuildType type;
  std::cout << "Builds\n";
  for (const auto& i: map1.getBuilds()){
    std::cout << i.second.owner.getColor() << std::endl;
    type = i.first.getType();
    std::cout << "Tipo ";
    switch (type){
      case FORT:{
        std::cout << "FORT";
        break;
      }
      case ROBOTF:{
        std::cout << "ROBOTF";
        break;
      }
      case VEHICLEF:{
        std::cout << "VEHICLEF";
        break;
      }
    }
    std::cout << " Posicion: " << i.second.position.getX()
              << " " << i.second.position.getY() << std::endl;
  }
}

