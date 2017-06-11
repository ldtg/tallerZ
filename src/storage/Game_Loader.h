//
// Created by darius on 01/06/17.
//

#ifndef TALLERZ_MAP_LOADER_H
#define TALLERZ_MAP_LOADER_H

#include <fstream>
#include <Exceptions/Storage_Exceptions/Storage_Exception.h>
#include <common/Map/Position.h>
#include <common/Map/Tile.h>
#include <common/States/BuildState.h>
#include <common/IDs/BuildID.h>
#include <server/model/Build.h>
#include <common/States/TerrainObjectState.h>
#include <common/IDs/TerrainObjectID.h>
#include <server/model/GaiaPlayer.h>
#include <common/Map/Map.h>
#include <server/model/Vehicle.h>
#include <server/model/CapturableVehicle.h>
#include <server/model/Territory.h>
#include <server/model/TerrainObject.h>
#include <map_generation/Generator.h>
#include "../../json/src/json.hpp"
#include <server/model/Data.h>
using json = nlohmann::json;

struct Map_Config {
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
class Game_Loader {
 private:
  json j;
  std::string file_path;
  std::ifstream map_file;

  std::map<Position, Tile> map;
  std::map<BuildID, BuildState> buildmap;
  std::map<BuildID, Build *> builds;
  std::map<UnitID, UnitState> units;
  std::map<CapturableID, Capturable *> controller_capturables;
  std::map<int, std::vector<Build *>> territory_buildings;
  std::map<TerrainObjectID, TerrainObject> controller_terrainObjects;
  std::map<UnitID, Unit *> controller_units;
  std::map<PlayerID, Player *> players;
  std::map<TeamID, Team> teams;
  Map_Config configuration;

  std::map<TerrainObjectID, TerrainObjectState> terrainObjects;
  std::map<CapturableID, CapturableState> capturables;

  GaiaPlayer &gaiaPlayer;
  Team gaiaTeam;
 public:
  Game_Loader(const std::string &file_path,
              const std::map<PlayerID, Player *> &players,
              const std::map<TeamID, Team> &teams,
              GaiaPlayer &gaia);

  ~Game_Loader();

  json get_json();
  std::map<BuildID, Build *> get_builds() const;
  std::map<BuildID, BuildState> get_buildmap() const;
  Map_Config get_configuration();
  std::map<Position, Tile> get_loaded_map() const;
  std::map<CapturableID, CapturableState> get_capturables() const;
  std::map<CapturableID, Capturable *> get_controller_capturables() const;
  std::map<TerrainObjectID, TerrainObjectState> get_terrainObject() const;
  std::map<UnitID, Unit *> get_controller_units() const;
  std::map<int, std::vector<Build *>> get_territory_buildings() const;
  std::map<TerrainObjectID, TerrainObject> get_controller_terrainObjects()const;
  std::map<PlayerID, Player *> get_players() const;
  std::map<TeamID, Team> get_teams() const;

  Map run() {
    this->load_file();
    this->load_configuration();
    this->build_map();
    return Map(map, buildmap, capturables, terrainObjects, units,
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

  void emplace_terrain(const Position_Data &pos_data);

  void assign_fort(const Position_Data &position_data,
                   Player &player,
                   Team &team);

  void assign_robot_factory(const Position_Data &position_data,
                            Player &player,
                            Team &team);

  void assign_vehicle_factory(const Position_Data &position_data,
                              Player &player,
                              Team &team);

  void assign_terrain_object(const Position_Data &position_data);

  void assign_capturable(const Position_Data &position_data);

  void assign_unit(const Position_Data &position_data);

  Position_Data read_data(int position);

  Position centered_position(int x, int y);

  Team get_team(Player *player);

  void open_file();

  void close_file();
};

#endif //TALLERZ_MAP_LOADER_H
