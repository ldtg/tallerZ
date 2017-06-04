//
// Created by darius on 01/06/17.
//

#ifndef TALLERZ_MAP_LOADER_H
#define TALLERZ_MAP_LOADER_H

#include <fstream>
#include <TerrainType.h>
#include <Exceptions/Storage_Exceptions/Storage_Exception.h>
#include <model/Position.h>
#include <model/Tile.h>
#include <map_generation/Generator.h>
#include <Data.h>
#include <model/BuildState.h>
#include <model/BuildID.h>
#include <model/Build.h>
#include "../../json/src/json.hpp"

using json = nlohmann::json;

struct Map_Config{
  int territories_amount;
  int teams;
  int map_width;
  int map_length;
  int factories_level;
  int max_units;
  int bridge_type;
  int road_type;
  int river_type;
  int base_terrain;
  int rock_type;
};

/**
 * @class Map_Loader
 * La funcionalidad de esta clase es cargar un mapa a partir
 * de un archivo .json
 */
class Map_Loader {
 private:
  json j;
  std::string file_path;
  std::ifstream map_file;

  std::map<Position, Tile> loaded_map;
  std::map<BuildID, BuildState> buildmap;
  std::map<BuildID, Build *> builds;
  std::map<CapturableID, Capturable *> capturables;
  std::vector<Player> players;
  std::vector<Team> teams;
  Map_Config configuration;

 public:
  Map_Loader(std::string file_path);

  ~Map_Loader();

  json get_json();

  std::vector<Team> get_teams(){
    return this->teams;
  }

  std::vector<Player> get_players(){
    return this->players;
  }
  std::map<BuildID, Build *> get_builds(){
    return this->builds;
  };
  std::map<BuildID, BuildState> get_buildmap(){
    return this->buildmap;
  };
  std::map<Position, Tile> get_loaded_map(){
    return this->loaded_map;
  };

  void load_file();//paso 0

  void load_configuration();//paso 1

  void set_players();//paso 2

  //paso_3
  void set_teams(){
    /**@WARNING muy HARCODEADO esto**/
    Team team1;
    team1.addPlayer(&players[0]);
    team1.addPlayer(&players[1]);
    Team team2;
    team2.addPlayer(&players[2]);
    //team2.addPlayer(&players[3]);
    this->teams.push_back(team1);
    this->teams.push_back(team2);
  }

  Map_Config get_configuration();

  void emplace_terrain(const Position_Data& pos_data){
    this->loaded_map.emplace(Position(pos_data.x, pos_data.y),
                             Tile(centered_position(pos_data.x, pos_data.y),
                                  data.get_terrain_data(pos_data.terrain_type)));
  }

  void assign_fort(const Position_Data& position_data, Player& player, Team& team){
    Build * build = new
        Build(data.fort,
              centered_position(position_data.x, position_data.y),
              player,
              team,
              configuration.factories_level);
    buildmap.emplace(build->getId(), build->getBuildState());
    builds.emplace(build->getId(), build);
  }

  void assign_robot_factory(const Position_Data& position_data, Player& player, Team& team);

  void assign_vehicle_factory(const Position_Data& position_data, Player& player, Team& team){
    Build * build = new
        Build(data.vehicleFactory,
              centered_position(position_data.x, position_data.y),
              player,
              team,
              configuration.factories_level);
    buildmap.emplace(build->getId(), build->getBuildState());
    builds.emplace(build->getId(), build);
  }

  void build_map(){
    Position_Data pos_data;
    int fort_to_assign = 0;
    int tile_amount = configuration.map_width * configuration.map_length;
    for (int i = 0; i < tile_amount; i++){
      pos_data = read_data(i);
      emplace_terrain(pos_data);
      if (pos_data.fort){
        assign_fort(pos_data, players[fort_to_assign],teams[0]);//teams[0] HARCODEADO
        fort_to_assign++;
      }
//      if (pos_data.robot_factory){
//        assign_robot_factory(pos_data, players[0], teams[0]);
//      }
//      if (pos_data.vehicle_factory){
//        assign_vehicle_factory(pos_data, players[0], teams[0]);//players[0] harcodeado tambien, osea, me quedo pensando en la idea esa del player especial que comentaba luis en clase la vez pasada.

    }
  }

  Position_Data read_data(int position);

  Position centered_position(int x, int y);

 private:

  void open_file();

  void close_file();
};

#endif //TALLERZ_MAP_LOADER_H
