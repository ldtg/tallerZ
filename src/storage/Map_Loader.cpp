//
// Created by darius on 01/06/17.
//

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
  this->configuration.teams = j["teams"];
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
  for (int i = 0; i < configuration.teams; i++){
    players.push_back(Player((PlayerColor)i));
  }
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
