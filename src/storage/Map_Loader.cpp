//
// Created by darius on 01/06/17.
//

#include <model/UnitFactory.h>
#include "Map_Loader.h"
void Map_Loader::open_file() {
  try{
    this->map_file.open(this->file_path);
  } catch (const std::exception& e){
    throw Storage_Exception(
        "Error en la apertura del archivo %s de donde se iba a cargar el "
            "mapa en el metodo open_file de Map_Loader: %s",
        this->file_path.c_str(),e.what());
  }
}
void Map_Loader::close_file() {
  try {
    this->map_file.close();
  } catch (const std::exception& e){
    throw Storage_Exception(
        "Error el metodo close_file de Map_Loader al cerrar el archivo %s: "
            "%s\n",this->file_path,e.what());
  }
}
Map_Loader::Map_Loader(std::string file_path) : file_path(file_path){
  open_file();
}
Map_Loader::~Map_Loader() {
  close_file();
}
json Map_Loader::get_json() {
  return this->j;
}
void Map_Loader::load_file() {
  map_file >> this->j;
}

void Map_Loader::load_configuration() {
  this->configuration.max_units = j["max_units"];
  this->configuration.factories_level = j["factories_level"];
  this->configuration.map_width = j["map_width"];
  this->configuration.map_length = j["map_length"];
  this->configuration.players = j["players"];
  this->configuration.territories_amount = j["territories_amount"];
  this->configuration.base_terrain = j["base_terrain"];
  this->configuration.bridge_type = j["bridge_type"];
  this->configuration.river_type = j["river_type"];
  this->configuration.road_type = j["road_type"];
  this->configuration.rock_type = j["rock_type"];
}

Position Map_Loader::centered_position(int x, int y) {
  int _x, _y;
  _x = ( x*TILEWIDHT + TILEWIDHT/2);
  _y = ( y*TILEHEIGHT + TILEHEIGHT/2);
  return Position(_x,_y);
}
/**
 * read_data: devuelve un struct de tipo Position_Data a partir del
 * archivo json con los elementos de el mapa en esa posicion.
 */
Position_Data Map_Loader::read_data(int position) {
  Position_Data data;
  std::string pos = std::to_string(position);
  data.x = this->j[pos]["x"];
  data.y = this->j[pos]["y"];
  data.vehicle_factory = this->j[pos]["vehicle_factory"];
  data.vehicle = this->j[pos]["vehicle"];
  data.territory = this->j[pos]["territory"];
  data.terrain_type = this->j[pos]["terrain_type"];
  data.rock = this->j[pos]["rock"];
  data.robot_factory = this->j[pos]["robot_factory"];
  data.fort = this->j[pos]["fort"];
  data.flag = this->j[pos]["flag"];
  data.bridge = this->j[pos]["bridge"];
  return data;
}
Map_Config Map_Loader::get_configuration() {
  return this->configuration;
}
void Map_Loader::set_players() {
  for (int i = 0; i < configuration.players; i++){
    players.push_back(Player((PlayerColor)i));
  }
  players.push_back(gaiaPlayer);
}
void Map_Loader::assign_robot_factory(const Position_Data &position_data, Player &player, Team &team) {
  Build * build = new
      Build(data.robotFactory,
            centered_position(position_data.x, position_data.y),
            player,
            team,
            configuration.factories_level);
  buildmap.emplace(build->getId(), build->getBuildState());
  builds.emplace(build->getId(), build);
}
void Map_Loader::set_teams() {
  const int team_amount = 2;
  Team team1;
  Team team2;
  for (int i = 0; i < configuration.players; i++){
    if ( i % team_amount == 0){
      team1.addPlayer(&players[i]);
    } else {
      team2.addPlayer(&players[i]);
    }
  }

  this->gaiaTeam.addPlayer(&gaiaPlayer);
  this->teams.push_back(team1);
  this->teams.push_back(team2);
  this->teams.push_back(gaiaTeam);
}
void Map_Loader::emplace_terrain(const Position_Data &pos_data) {
  this->map.emplace(Position(pos_data.x, pos_data.y),
                           Tile(centered_position(pos_data.x, pos_data.y),
                                data.get_terrain_data(pos_data.terrain_type)));
}
void Map_Loader::assign_fort(const Position_Data &position_data, Player &player, Team &team) {
  Build * build = new
      Build(data.fort,
            centered_position(position_data.x, position_data.y),
            player,
            team,
            configuration.factories_level);
  buildmap.emplace(build->getId(), build->getBuildState());
  builds.emplace(build->getId(), build);
}
void Map_Loader::assign_vehicle_factory(const Position_Data &position_data, Player &player, Team &team) {
  Build * build = new
      Build(data.vehicleFactory,
            centered_position(position_data.x, position_data.y),
            player,
            team,
            configuration.factories_level);
  buildmap.emplace(build->getId(), build->getBuildState());
  builds.emplace(build->getId(), build);
}
void Map_Loader::build_map() {
  Position_Data pos_data;
  int fort_to_assign = 0;
  int tile_amount = configuration.map_width * configuration.map_length;
  for (int i = 0; i < tile_amount; i++){
    pos_data = read_data(i);
    emplace_terrain(pos_data);
    if (pos_data.fort){
      assign_fort(pos_data, players[fort_to_assign],teams[0]);//players[0] HARCODEADO
      fort_to_assign++;
    }
    if (pos_data.bridge || pos_data.rock){
      assign_terrain_object(pos_data);
    }
    if (pos_data.vehicle || pos_data.flag){
      assign_capturable(pos_data);
    }
    if (pos_data.robot_factory){
      assign_robot_factory(pos_data, gaiaPlayer, teams[0]);//TODO desharcodear teams[0]
    }
    if (pos_data.vehicle_factory){
      assign_vehicle_factory(pos_data, gaiaPlayer, teams[0]);//TODO desharcodear teams[0]
    }
  }
}
std::vector<Team> Map_Loader::get_teams() {
  return this->teams;
}
std::vector<Player> Map_Loader::get_players() {
  return this->players;
}
std::map<BuildID, Build *> Map_Loader::get_builds() {
  return this->builds;
}
std::map<BuildID, BuildState> Map_Loader::get_buildmap() {
  return this->buildmap;
}
std::map<Position, Tile> Map_Loader::get_loaded_map() {
  return this->map;
}
void Map_Loader::assign_terrain_object(const Position_Data& position_data) {
  Position pos(position_data.x, position_data.y);

  const int size = 50;
  const int bridge_health = 1000;
  const int rock_health = 10;

  if (position_data.bridge) {
    TerrainObjectState objectState(pos, size, bridge_health, true);
    switch (configuration.bridge_type) {
      case TerrainType::WOODENBRIDGE:
        terrainObject[TerrainObjectID(_WOODENBRIDGE)] = objectState;
        //TODO ver como afecta esto a la creacion de objectID
      case TerrainType::ASPHALTEDBRIDGE:
        terrainObject[TerrainObjectID(_ASPHALTEDBRIDGE)] = objectState;
        //TODO ver como afecta esto a la creacion de objectID
    }
  }

  if (position_data.rock){
    TerrainObjectState objectState(pos, size, rock_health, false);
    switch (configuration.rock_type){
      case (TerrainObjectType ::ROCK):{
        this->terrainObject.emplace(TerrainObjectID(ROCK),objectState);
        break;
      }
      case (TerrainObjectType ::ICEROCK):{
        this->terrainObject.emplace(TerrainObjectID(ICEROCK),objectState);
        break;
      }
    }
  }
}
void Map_Loader::assign_capturable(const Position_Data &position_data) {
  Position pos(position_data.x, position_data.y);
  if (position_data.flag){
    capturables.emplace(CapturableID(FLAG), CapturableState(GaiaPlayer().getID(), pos));
  }
  if (position_data.vehicle){
    capturables.emplace(CapturableID(UNIT), CapturableState(GaiaPlayer().getID(), pos));
    assign_unit(position_data);
  }
}
std::map<CapturableID, CapturableState> Map_Loader::get_capturables() {
  return this->capturables;
}
std::map<TerrainObjectID, TerrainObjectState> Map_Loader::get_terrainObject() {
  return this->terrainObject;
}
void Map_Loader::assign_unit(const Position_Data &position_data) {
  Position pos(position_data.x, position_data.y);
  Unit* unit = UnitFactory::createUnitDynamic(pos,V_JEEP,gaiaPlayer,gaiaTeam);
  this->units.emplace(unit->getId(), unit->getUnitState());
  this->controller_units.emplace(unit->getId(), unit);
}
std::map<UnitID, Unit *> Map_Loader::get_controller_units() {
  return this->controller_units;
}
