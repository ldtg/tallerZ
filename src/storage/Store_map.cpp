//
// Created by darius on 08/05/17.
//

#include "Store_map.h"
Store_map::Store_map(std::string file_name, Generator &generator) :
    generated_map(generator), file_name(file_name){
  this->open_file();
}
Store_map::~Store_map() {
  this->close_file();
}
/**
 * open_file: abre el archivo en donde se va a escribir
 * con el nombre del atributo file_name
 */
void Store_map::open_file() {
  try{
    this->json_file.open(this->file_name);
  } catch (const std::exception& e){
    throw Storage_Exception(
        "Error en la apertura del archivo %s en donde se iba a guardar el "
            "mapa en el metodo open_file de Store_map: %s",
        this->file_name.c_str(),e.what());
  }
}
/**
 * close_file: cierra el archivo .json
 */
void Store_map::close_file() {
  try {
    this->json_file.close();
  } catch (const std::exception& e){
    throw Storage_Exception(
        "Error el metodo close_file de Store_map al cerrar el archivo %s: "
            "%s\n",this->file_name,e.what());
  }
}
/**
  * load_json: transforma un mapa generado por el Generator
  * en un archivo .json
  */
void Store_map::load_json() {
  this->j["map_length"] = generated_map.map_length;
  this->j["map_width"] = generated_map.map_width;
  this->j["territories_amount"] = generated_map.territories;
  this->j["factories_level"] = generated_map.factories_level;
  this->j["max_units"] = generated_map.max_units;
  this->j["base_terrain"] = generated_map.base_terrain;
  this->j["rock_type"] = generated_map.rock_type;
  this->j["river_type"] = generated_map.river_type;
  this->j["teams"] = generated_map.teams;

  for (int i = 0; i < generated_map.tile_amount; i++){
    j[std::to_string(i)] = {
        {"x", generated_map.map_positions[i].x},
        {"y", generated_map.map_positions[i].y},
        {"bridge", generated_map.map_positions[i].bridge},
        {"territory", generated_map.map_positions[i].territory},
        {"terrain_type", generated_map.map_positions[i].terrain_type},
        {"fort", generated_map.map_positions[i].fort},
        {"flag", generated_map.map_positions[i].flag},
        {"robot_factory", generated_map.map_positions[i].robot_factory},
        {"vehicle_factory", generated_map.map_positions[i].vehicle_factory},
        {"rock", generated_map.map_positions[i].rock},
        {"vehicle", generated_map.map_positions[i].vehicle}
    };
  }
}
json Store_map::get_json() {
  return this->j;
}
void Store_map::operator()() {
  try {
    load_json();
    json_file << std::setw(4) << j << std::endl;
  } catch (const std::exception& e){
    throw Storage_Exception("Error en Store_map: %s\n", e.what());
  }
}
