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
/**
 * get_terrain_data: Devuelve el tipo de TerrainData acorde al
 * parametro terrain que puede ser: land, prairie, water, lava,
 * swamp, road, bridge o snow.
 * @param terrain : tipo de terreno
 * @return TerrainData
 */
TerrainData Map_Loader::get_terrain_data(TerrainType terrain) {
  //TODO: habría que diferenciar segun los tipos de terrenos como los que estan en terrain_type: land, prairie, water, lava, swamp (no esta), road, bridge (no esta), snow.
  switch (terrain){
    case PRAIRIE:
      return data.land;
    case ROAD:
      return data.road;
    case LAND:
      return data.land;
    case SWAMP:
      return data.water;
    case LAVA:
      return data.lava;
    case SNOW:
      return data.land;
    default:
      return data.land;
  }
}
void Map_Loader::load_configuration() {
  this->configuration.max_units = j["max_units"];
  this->configuration.factories_level = j["factories_level"];
  this->configuration.map_width = j["map_width"];
  this->configuration.map_length = j["map_length"];
  this->configuration.teams = j["teams"];
  this->configuration.territories_amount = j["territories_amount"];
}
Position Map_Loader::centered_position(int x, int y) {
  int _x, _y;
  _x = ( x + TILEWIDHT/2);
  _y = ( y + TILEHEIGHT/2);
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
