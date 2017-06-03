#ifndef TALLERZ_MAP_STORAGE_H
#define TALLERZ_MAP_STORAGE_H

#include <map>
#include <iostream>
#include <fstream>
#include <Exceptions/Storage_Exceptions/Storage_Exception.h>
#include "map_generation/Generator.h"
#include "../../json/src/json.hpp"

using json = nlohmann::json;

/**
 * @class Store_map
 * Guarda un mapa generado por el Generator en un archivo
 * de formato .json
 */
class Store_map {
 private:
  std::string file_name;
  std::ofstream json_file;
  Generator& generated_map;
  json j;

 public:
  Store_map(std::string file_name, Generator& generator);

  ~Store_map();

  void operator()();

  json get_json();

 private:
  void open_file();

  void close_file();

  void load_json();
};

#endif //TALLERZ_MAP_STORAGE_H
