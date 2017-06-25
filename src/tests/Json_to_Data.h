//
// Created by darius on 18/06/17.
//

#ifndef TALLERZ_SERVIDOR_JSON_TO_DATA_H
#define TALLERZ_SERVIDOR_JSON_TO_DATA_H

#include <json.hpp>
#include <fstream>
#include <Exceptions/Storage_Exceptions/Storage_Exception.h>
#include <server/model/Weapon.h>

using nlohmann::json;

class Data;

class Json_to_Data {
 private:
  Data& data;
  json j;
  std::ifstream json_file;
  const std::string file_path = "data.json";

 public:
  Json_to_Data(Data& data);

  void load_file();

  Weapon& get_weapon(const WeaponType& weaponType);

 private:
  void open_file(){
    try {
      this->json_file.open(this->file_path);
    } catch (const std::ifstream::failure &e) {
      throw Storage_Exception(
          "Error en la apertura del archivo %s de donde se iba a cargar la "
              "variable Data\n: %s\n", this->file_path.c_str(), e.what());
    }
  }

  void close_file(){
    try {
      this->json_file.close();
    } catch (const std::ifstream::failure &e) {
      throw Storage_Exception(
          "Error el metodo close_file de Json_to_Data al cerrar el archivo "
              "%s: %s\n", this->file_path, e.what());
    }
  }
};

#endif //TALLERZ_SERVIDOR_JSON_TO_DATA_H
