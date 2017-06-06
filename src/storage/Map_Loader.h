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
#include <model/TerrainObjectState.h>
#include <model/TerrainObjectID.h>
#include <model/GaiaPlayer.h>
#include <model/Map.h>
#include <model/Vehicle.h>
#include "../../json/src/json.hpp"

using json = nlohmann::json;

struct Map_Config{
  int territories_amount;
  int players;
  int map_width;
  int map_length;
  int factories_level;
  int max_units;
  TerrainType bridge_type;
  TerrainType road_type;
  TerrainType river_type;
  TerrainType base_terrain;
  TerrainObjectType rock_type;
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

  std::map<Position, Tile> map;
  std::map<BuildID, BuildState> buildmap;
  std::map<BuildID, Build *> builds;
  std::map<UnitID, UnitState> units;
  std::vector<Player> players;
  std::vector<Team> teams;
  Map_Config configuration;

  std::map<TerrainObjectID, TerrainObjectState> terrainObject;
  std::map<CapturableID, CapturableState> capturables;
  GaiaPlayer gaiaPlayer;

 public:
  Map_Loader(std::string file_path);

  ~Map_Loader();

  json get_json();
  std::vector<Team> get_teams();
  std::vector<Player> get_players();
  std::map<BuildID, Build *> get_builds();
  std::map<BuildID, BuildState> get_buildmap();
  Map_Config get_configuration();
  std::map<Position, Tile> get_loaded_map();
  std::map<CapturableID, CapturableState> get_capturables();
  std::map<TerrainObjectID, TerrainObjectState> get_terrainObject();

  Map run(){
    this->load_file();
    this->load_configuration();
    this->set_players();
    this->set_teams();
    this->build_map();
    return Map(map, buildmap, capturables, terrainObject, units,
               configuration.map_width, configuration.map_length);
  }

 private:
  /**
   * load_file: convierte el archivo .json en una variable de tipo json.
   */
  void load_file();//paso 0

  /**
   * load_configuration: selecciona las variables de configuracion guardadas
   * en el archivo .json y las almacena en la variable configuration
   */
  void load_configuration();//paso 1

  /**
   * set_players: carga las variables de jugadores en base a la cantidad
   * de jugadores para los que está diseñado el mapa.
   */
  void set_players();//paso 2

  /**
   * set_teams: reparte los jugadores en dos equipos que se van a enfrentar
   * entre sí.
   */
  void set_teams();//paso 3

  /**
   * build_map: carga todos los elementos del mapa
   */
  void build_map();//paso 4

  void emplace_terrain(const Position_Data& pos_data);

  void assign_fort(const Position_Data& position_data, Player& player, Team& team);

  void assign_robot_factory(const Position_Data& position_data, Player& player, Team& team);

  void assign_vehicle_factory(const Position_Data& position_data, Player& player, Team& team);

  void assign_terrain_object(const Position_Data& position_data);

  void assign_capturable(const Position_Data& position_data);

  void assign_unit(const Position_Data& position_data);

  Position_Data read_data(int position);

  Position centered_position(int x, int y);

  void open_file();

  void close_file();
};

#endif //TALLERZ_MAP_LOADER_H
