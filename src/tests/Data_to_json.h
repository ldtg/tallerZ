//
// Created by darius on 18/06/17.
//

#ifndef TALLERZ_SERVIDOR_DATA_TO_JSON_H
#define TALLERZ_SERVIDOR_DATA_TO_JSON_H

#include <json.hpp>
#include <server/model/Data.h>
#include <fstream>
#include <Exceptions/Storage_Exceptions/Storage_Exception.h>

using nlohmann::json;

class Data_to_json {
 private:
  Data data;
  json j;
  const std::string& file_name = "data.json";
  std::ofstream json_file;

 public:
  Data_to_json(){
    open_file();
  }

  ~Data_to_json(){
    close_file();
  }

  void store_data(){
    j["ticksPerSec"] = 10;
    j["playerInitialTerritories"] = 1;
    j["playerInitialUnits"] = 0;
    j["defaultDriver"] = R_GRUNT;
    j["rangeMultipliquer"] = 10;

    j["bullet.type"] = WeaponType::BULLET;
    j["bullet.damage"] = 2;
    j["bullet.isExplosive"] = false;
    j["bullet.speed"] = 0;

    j["rocket.type"] = WeaponType::ROCKET;
    j["rocket.damage"] = 25;
    j["rocket.isExplosive"] = true;
    j["rocket.speed"] = 13;

    j["flamethrower.type"] = WeaponType::FIRE;
    j["flamethrower.damage"] = 10;
    j["flamethrower.isExplosive"] = true;
    j["flamethrower.speed"] = 12;

    j["r_grunt.type"] = UnitType::R_GRUNT;
    j["r_grunt.weapon"] = WeaponType ::BULLET; //aca ver como pasar de string a tipo bullet.
    j["r_grunt.secsUntilFire"] = 0.5;
    j["r_grunt.health"] = 10;
    j["r_grunt.range"] = 7;//el rango lo aumentan solo las unidades con el range mult
    j["r_grunt.speed"] = 4;
    j["r_grunt.factoryRate"] = 3;
    j["r_grunt.factoryBaseTimeInSec"] = 30;
    j["r_grunt.factoryMinimunTechLevel"] = 1;

    j["r_tough.type"] = UnitType::R_TOUGH;
    j["r_tough.weapon"] = WeaponType ::ROCKET;
    j["r_tough.secsUntilFire"] = 0.5;
    j["r_tough.health"] = 300;
    j["r_tough.range"] = 10;
    j["r_tough.speed"] = 4;
    j["r_tough.factoryRate"] = 2;
    j["r_tough.factoryBaseTimeInSec"] = 20;//742
    j["r_tough.factoryMinimunTechLevel"] = 2;

    j["r_pyro.type"] = UnitType::R_PYRO;
    j["r_pyro.weapon"] = WeaponType ::FIRE;
    j["r_pyro.secsUntilFire"] = 0.5;
    j["r_pyro.health"] = 100;
    j["r_pyro.range"] = 6;
    j["r_pyro.speed"] = 4;
    j["r_pyro.factoryRate"] = 4;
    j["r_pyro.factoryBaseTimeInSec"] = 10;
    j["r_pyro.factoryMinimunTechLevel"] = 1;

    j["v_jeep.type"] = UnitType::V_JEEP;
    j["v_jeep.weapon"] = WeaponType ::BULLET;
    j["v_jeep.secsUntilFire"] = 0.17;
    j["v_jeep.health"] = 10;
    j["v_jeep.range"] = 5;//6x5
    j["v_jeep.speed"] = 8;
    j["v_jeep.factoryRate"] = 1;
    j["v_jeep.factoryBaseTimeInSec"] = 40;
    j["v_jeep.factoryMinimunTechLevel"] = 1;

    j["fort.type"] = BuildType::FORT;
    j["fort.health"] = 1000;
    j["fort.size"] = 50;

    j["robotFactory.type"] = BuildType::ROBOTF;
    j["robotFactory.health"] = 1000;
    j["robotFactory.size"] = 50;

    j["vehicleFactory.type"] = BuildType::VEHICLEF;
    j["vehicleFactory.health"] = 1000;
    j["vehicleFactory.size"] = 50;

    j["land.type"] = TerrainType::LAND;
    j["land.terrainFactor"] = 1;
    j["prairie.type"] = TerrainType::PRAIRIE;
    j["prairie.terrainFactor"] = 1;
    j["snow.type"] = TerrainType::SNOW;
    j["snow.terrainFactor"] = 1;
    j["water.type"] = TerrainType::WATER;
    j["water.terrainFactor"] = 0.7;
    j["swamp.type"] = TerrainType::SWAMP;
    j["swamp.terrainFactor"] = 0.7;
    j["road.type"] = TerrainType::ROAD;
    j["road.terrainFactor"] = 2;
    j["asphaltedRoad.type"] = TerrainType::ASPHALTEDROAD;
    j["asphaltedRoad.terrainFactor"] = 2;
    j["lava.type"] = TerrainType::LAVA;
    j["lava.terrainFactor"] = 0.1; //no importa el valor

    j["asphaltedBridgeTerrain.type"] = TerrainType::ASPHALTEDBRIDGE;
    j["asphaltedBridgeTerrain.terrainFactor"] = 1;
    j["woodenBridge.type"] = TerrainType::WOODENBRIDGE;
    j["woodenBridge.terrainFactor"] = 1;

    j["asphaltedBridgeObject.type"] = TerrainObjectType::_ASPHALTEDBRIDGE;
    j["asphaltedBridgeObject.passable"] = true;
    j["asphaltedBridgeObject.health"] = 1000;
    j["asphaltedBridgeObject.size"] = 50;
    j["rockObject.type"] = TerrainObjectType::ROCK;
    j["rockObject.passable"] = false;
    j["rockObject.health"] = 1000;//1000
    j["rockObject.size"] = 50;
    j["woodenBridgeObject.type"] = TerrainObjectType::_WOODENBRIDGE;
    j["woodenBridgeObject.passable"] = true;
    j["woodenBridgeObject.health"] = 10;
    j["woodenBridgeObject.size"] = 50;
    j["iceRockObject.type"] = TerrainObjectType::ICEROCK;
    j["iceRockObject.passable"] = false;
    j["iceRockObject.health"] = 1000;
    j["iceRockObject.size"] = 50;

    json_file << std::setw(4) << j << std::endl;
  }

 private:
  void open_file(){
    try{
      this->json_file.open(this->file_name);
    } catch (const std::exception& e){
      throw Storage_Exception(
          "Error en la apertura del archivo %s en donde se iba a guardar el "
              "mapa en el metodo open_file de Store_map: %s",
          this->file_name.c_str(),e.what());
    }
  }

  void close_file(){
    try {
      this->json_file.close();
    } catch (const std::exception& e){
      throw Storage_Exception(
          "Error el metodo close_file de Store_map al cerrar el archivo %s: "
              "%s\n",this->file_name,e.what());
    }
  }
};

#endif //TALLERZ_SERVIDOR_DATA_TO_JSON_H
