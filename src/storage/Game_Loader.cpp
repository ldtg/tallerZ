//
// Created by darius on 01/06/17.
//

#include <model/UnitFactory.h>
#include "Game_Loader.h"
void Game_Loader::open_file() {
  try{
    this->map_file.open(this->file_path);
  } catch (const std::exception& e){
    throw Storage_Exception(
        "Error en la apertura del archivo %s de donde se iba a cargar el "
            "mapa en el metodo open_file de Game_Loader: %s",
        this->file_path.c_str(),e.what());
  }
}
void Game_Loader::close_file() {
  try {
    this->map_file.close();
  } catch (const std::exception& e){
    throw Storage_Exception(
        "Error el metodo close_file de Game_Loader al cerrar el archivo %s: "
            "%s\n",this->file_path,e.what());
  }
}
Game_Loader::Game_Loader(std::string file_path) : file_path(file_path){
  open_file();
}
Game_Loader::~Game_Loader() {
  close_file();
}
json Game_Loader::get_json() {
  return this->j;
}
void Game_Loader::load_file() {
  map_file >> this->j;
}

void Game_Loader::load_configuration() {
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

Position Game_Loader::centered_position(int x, int y) {
  int _x, _y;
  _x = ( x*TILEWIDHT + TILEWIDHT/2);
  _y = ( y*TILEHEIGHT + TILEHEIGHT/2);
  return Position(_x,_y);
}
/**
 * read_data: devuelve un struct de tipo Position_Data a partir del
 * archivo json con los elementos de el mapa en esa posicion.
 */
Position_Data Game_Loader::read_data(int position) {
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
Map_Config Game_Loader::get_configuration() {
  return this->configuration;
}
void Game_Loader::set_players() {
  for (int i = 0; i < configuration.players; i++){
    Player * player = new Player((PlayerColor)i);
    players[player->getID()] = player;
  }
}
void Game_Loader::assign_robot_factory(const Position_Data &position_data, Player &player, Team &team) {
  Build * build = new
      Build(data.robotFactory,
            centered_position(position_data.x, position_data.y),
            player,
            team,
            configuration.factories_level);
  buildmap.emplace(build->getId(), build->getBuildState());
  territory_buildings[position_data.territory].push_back(build);
  builds.emplace(build->getId(), build);
}
void Game_Loader::set_teams() {
  const int team_amount = 2;
  Team team1;
  Team team2;
  for (const auto& i: players){
    int player_id = (i.first.getID());
    if (player_id % team_amount == 0){
      team1.addPlayer(i.second);
    } else {
      team2.addPlayer(i.second);
    }
  }
//  std::map<TeamID, Team> teams;

  teams.emplace(team1.getID(), team1);
  teams.emplace(team2.getID(), team2);
  this->gaiaTeam.addPlayer(&gaiaPlayer);
}
void Game_Loader::emplace_terrain(const Position_Data &pos_data) {
  this->map.emplace(Position(pos_data.x, pos_data.y),
                           Tile(centered_position(pos_data.x, pos_data.y),
                                data.get_terrain_data(pos_data.terrain_type)));
}
void Game_Loader::assign_fort(const Position_Data &position_data, Player &player, Team &team) {
  Build * build = new
      Build(data.fort,
            centered_position(position_data.x, position_data.y),
            player,
            team,
            configuration.factories_level);
  buildmap.emplace(build->getId(), build->getBuildState());
  builds.emplace(build->getId(), build);
}
void Game_Loader::assign_vehicle_factory(const Position_Data &position_data, Player &player, Team &team) {
  Build * build = new
      Build(data.vehicleFactory,
            centered_position(position_data.x, position_data.y),
            player,
            team,
            configuration.factories_level);
  buildmap.emplace(build->getId(), build->getBuildState());
  territory_buildings[position_data.territory].push_back(build);
  builds.emplace(build->getId(), build);
}

Team Game_Loader::get_team(Player * player){
  bool encontrado;
  for (const auto team: teams) {
    if (team.second.isaPlayerOfTheTeam(player->getID())) {
      return team.second;
    }
  }
  throw std::exception();
}

void Game_Loader::build_map() {
  Position_Data pos_data;
  auto fort_player = players.begin();
  int tile_amount = configuration.map_width * configuration.map_length;
  for (int i = 0; i < tile_amount; i++){
    pos_data = read_data(i);
    emplace_terrain(pos_data);
    if (pos_data.fort){
      Team team = get_team(fort_player->second);
      assign_fort(pos_data, *fort_player->second, team);//players[0] HARCODEADO
      fort_player++;
    }
    if (pos_data.bridge || pos_data.rock){
      assign_terrain_object(pos_data);
    }
    if (pos_data.robot_factory){
      assign_robot_factory(pos_data, gaiaPlayer, gaiaTeam);
    }
    if (pos_data.vehicle_factory){
      assign_vehicle_factory(pos_data, gaiaPlayer, gaiaTeam);
    }
  }
  for (int i = 0; i < tile_amount; i++){
    pos_data = read_data(i);
    if (pos_data.vehicle || pos_data.flag){
      assign_capturable(pos_data);
    }
  }
}

std::map<BuildID, Build *> Game_Loader::get_builds() {
  return this->builds;
}
std::map<BuildID, BuildState> Game_Loader::get_buildmap() {
  return this->buildmap;
}
std::map<Position, Tile> Game_Loader::get_loaded_map() {
  return this->map;
}
void Game_Loader::assign_terrain_object(const Position_Data& position_data) {
  Position pos(position_data.x, position_data.y);
  if (position_data.bridge) {
    switch (configuration.bridge_type) {
      case TerrainType::WOODENBRIDGE:{
        TerrainObject wooden_bridge(data.getObjectData(_WOODENBRIDGE),
                                    centered_position(position_data.x,
                                                      position_data.y),
                                    &gaiaPlayer);

        terrainObjects[wooden_bridge.getID()] = wooden_bridge.getState();
        this->controller_terrainObjects.emplace(wooden_bridge.getID(),wooden_bridge);
        break;
      }
      case TerrainType::ASPHALTEDBRIDGE:{
        TerrainObject asphalted_bridge(data.getObjectData(_ASPHALTEDBRIDGE),
                                       centered_position(position_data.x,
                                                         position_data.y),
                                       &gaiaPlayer);

        terrainObjects[asphalted_bridge.getID()] = asphalted_bridge.getState();
        this->controller_terrainObjects.emplace(asphalted_bridge.getID(),asphalted_bridge);
        break;
      }
    }
  }

  if (position_data.rock){
    switch (configuration.rock_type){
      case (TerrainObjectType ::ROCK):{
        TerrainObject rock(data.getObjectData(ROCK),
                           centered_position(position_data.x,
                                             position_data.y),
                           &gaiaPlayer);
        this->terrainObjects.emplace(rock.getID(),rock.getState());
        break;
      }
      case (TerrainObjectType ::ICEROCK):{
        TerrainObject icerock(data.getObjectData(ICEROCK),
                           centered_position(position_data.x,
                                             position_data.y),
                           &gaiaPlayer);
        this->terrainObjects.emplace(icerock.getID(),icerock.getState());
        break;
      }
    }
  }
}
void Game_Loader::assign_capturable(const Position_Data &position_data) {
  Position pos(position_data.x, position_data.y);
  if (position_data.flag){
    Territory * territory = new
        Territory(centered_position(position_data.x, position_data.y),
                  territory_buildings[position_data.territory],
                  &gaiaPlayer, gaiaTeam);
    capturables.emplace(territory->getID(), territory->getCapturableState());
    controller_capturables.emplace(territory->getID(), territory);
  }
  if (position_data.vehicle){
    Vehicle* unit = UnitFactory::createVehicleDynamic(pos,V_JEEP,gaiaPlayer,gaiaTeam);
    this->units.emplace(unit->getId(), unit->getUnitState());
    this->controller_units.emplace(unit->getId(), unit);
    CapturableVehicle * vehicle = new CapturableVehicle(*unit);
    capturables.emplace(vehicle->getID(), vehicle->getCapturableState());
    controller_capturables.emplace(vehicle->getID(), vehicle);
  }
}
std::map<CapturableID, CapturableState> Game_Loader::get_capturables() {
  return this->capturables;
}
std::map<TerrainObjectID, TerrainObjectState> Game_Loader::get_terrainObject() {
  return this->terrainObjects;
}
void Game_Loader::assign_unit(const Position_Data &position_data) {
  Position pos(position_data.x, position_data.y);
  Unit* unit = UnitFactory::createUnitDynamic(pos,V_JEEP,gaiaPlayer,gaiaTeam);
  this->units.emplace(unit->getId(), unit->getUnitState());
  this->controller_units.emplace(unit->getId(), unit);
}
std::map<UnitID, Unit *> Game_Loader::get_controller_units() {
  return this->controller_units;
}
std::map<int, std::vector<Build *>> Game_Loader::get_territory_buildings() {
  return this->territory_buildings;
}
std::map<CapturableID, Capturable *> Game_Loader::get_controller_capturables() {
  return this->controller_capturables;
}
std::map<TerrainObjectID, TerrainObject> Game_Loader::get_controller_terrainObjects() {
  return this->controller_terrainObjects;
}
std::map<PlayerID, Player *> Game_Loader::get_players() {
  return this->players;
}
std::map<TeamID, Team> Game_Loader::get_teams() {
  return this->teams;
}
