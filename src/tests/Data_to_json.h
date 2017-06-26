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
    j["rangeMultipliquer"] = 15;

    j["bullet.type"] = WeaponType::BULLET;
    j["bullet.damage"] = 2;
    j["bullet.isExplosive"] = false;
    j["bullet.speed"] = 0;

    j["rocket.type"] = WeaponType::ROCKET;
    j["rocket.damage"] = 25;
    j["rocket.isExplosive"] = true;
    j["rocket.speed"] = 15;

    j["flamethrower.type"] = WeaponType::FIRE;
    j["flamethrower.damage"] = 10;
    j["flamethrower.isExplosive"] = true;
    j["flamethrower.speed"] = 15;

    j["laser.type"] = WeaponType::LASER;
    j["laser.damage"] = 10;
    j["laser.isExplosive"] = false;
    j["laser.speed"] = 15;

    j["hcbullet.type"] = WeaponType::HCBULLET;
    j["hcbullet.damage"] = 20;
    j["hcbullet.isExplosive"] = true;
    j["hcbullet.speed"] = 15;

    j["r_grunt.type"] = UnitType::R_GRUNT;
    j["r_grunt.weapon"] = WeaponType ::BULLET;
    j["r_grunt.secsUntilFire"] = 0.5;
    j["r_grunt.healthPercent"] = 60;
    j["r_grunt.range"] = 7;
    j["r_grunt.speed"] = 4;
    j["r_grunt.factoryRate"] = 3;
    j["r_grunt.factoryBaseTimeInSec"] = 575;
    j["r_grunt.factoryMinimunTechLevel"] = 1;

    j["r_tough.type"] = UnitType::R_TOUGH;
    j["r_tough.weapon"] = WeaponType ::ROCKET;
    j["r_tough.secsUntilFire"] = 0.5;
    j["r_tough.healthPercent"] = 300;
    j["r_tough.range"] = 5;
    j["r_tough.speed"] = 4;
    j["r_tough.factoryRate"] = 2;
    j["r_tough.factoryBaseTimeInSec"] = 742;
    j["r_tough.factoryMinimunTechLevel"] = 2;

    j["r_pyro.type"] = UnitType::R_PYRO;
    j["r_pyro.weapon"] = WeaponType ::FIRE;
    j["r_pyro.secsUntilFire"] = 0.5;
    j["r_pyro.healthPercent"] = 100;
    j["r_pyro.range"] = 6;
    j["r_pyro.speed"] = 4;
    j["r_pyro.factoryRate"] = 4;
    j["r_pyro.factoryBaseTimeInSec"] = 840;
    j["r_pyro.factoryMinimunTechLevel"] = 4;

    j["r_laser.type"] = UnitType::R_LASER;
    j["r_laser.weapon"] = WeaponType ::LASER;
    j["r_laser.secsUntilFire"] = 0.25;
    j["r_laser.healthPercent"] = 100;
    j["r_laser.range"] = 7;
    j["r_laser.speed"] = 4;
    j["r_laser.factoryRate"] = 5;
    j["r_laser.factoryBaseTimeInSec"] = 900;
    j["r_laser.factoryMinimunTechLevel"] = 5;

    j["r_psycho.type"] = UnitType::R_PSYCHO;
    j["r_psycho.weapon"] = WeaponType ::BULLET;
    j["r_psycho.secsUntilFire"] = 0.1;
    j["r_psycho.healthPercent"] = 80;
    j["r_psycho.range"] = 7;
    j["r_psycho.speed"] = 4;
    j["r_psycho.factoryRate"] = 3;
    j["r_psycho.factoryBaseTimeInSec"] = 600;
    j["r_psycho.factoryMinimunTechLevel"] = 2;

    j["r_sniper.type"] = UnitType::R_SNIPER;
    j["r_sniper.weapon"]= WeaponType ::BULLET;
    j["r_sniper.secsUntilFire"] = 0.25;
    j["r_sniper.healthPercent"] = 80;
    j["r_sniper.range"] = 10;
    j["r_sniper.speed"] = 4;
    j["r_sniper.factoryRate"] = 3;
    j["r_sniper.factoryBaseTimeInSec"] = 575;
    j["r_sniper.factoryMinimunTechLevel"] = 3;

    j["v_jeep.type"] = UnitType::V_JEEP;
    j["v_jeep.weapon"] = WeaponType ::BULLET;
    j["v_jeep.secsUntilFire"] = 0.17;
    j["v_jeep.healthPercent"] = 10;
    j["v_jeep.range"] = 5;//6x5
    j["v_jeep.speed"] = 8;
    j["v_jeep.factoryRate"] = 1;
    j["v_jeep.factoryBaseTimeInSec"] = 660;
    j["v_jeep.factoryMinimunTechLevel"] = 1;

    j["v_ltank.type"] = UnitType::V_LTANK;
    j["v_ltank.weapon"] = WeaponType ::HCBULLET;
    j["v_ltank.secsUntilFire"] = 2;
    j["v_ltank.healthPercent"] = 80;
    j["v_ltank.range"] = 6;
    j["v_ltank.speed"] = 6;
    j["v_ltank.factoryRate"] = 1;
    j["v_ltank.factoryBaseTimeInSec"] = 840;
    j["v_ltank.factoryMinimunTechLevel"] = 2;

    j["v_mtank.type"] = UnitType::V_MTANK;
    j["v_mtank.weapon"] = WeaponType ::HCBULLET;
    j["v_mtank.secsUntilFire"] = 2;
    j["v_mtank.healthPercent"] = 120;
    j["v_mtank.range"] = 7;
    j["v_mtank.speed"] = 5;
    j["v_mtank.factoryRate"] = 1;
    j["v_mtank.factoryBaseTimeInSec"] = 1080;
    j["v_mtank.factoryMinimunTechLevel"] = 3;

    j["v_htank.type"] = UnitType::V_HTANK;
    j["v_htank.weapon"] = WeaponType ::HCBULLET;
    j["v_htank.secsUntilFire"] = 2;
    j["v_htank.healthPercent"] = 180;
    j["v_htank.range"] = 8;
    j["v_htank.speed"] = 5;
    j["v_htank.factoryRate"] = 1;
    j["v_htank.factoryBaseTimeInSec"] = 1200;
    j["v_htank.factoryMinimunTechLevel"] = 4;

    j["v_mml.type"] = UnitType::V_MML;
    j["v_mml.weapon"] = WeaponType ::ROCKET;
    j["v_mml.secsUntilFire"] = 0.5;
    j["v_mml.healthPercent"] = 200;
    j["v_mml.range"] = 8;
    j["v_mml.speed"] = 5;
    j["v_mml.factoryRate"] = 1;
    j["v_mml.factoryBaseTimeInSec"] = 1320;
    j["v_mml.factoryMinimunTechLevel"] = 5;

    j["fort.type"] = BuildType::FORT;
    j["fort.healthPercent"] = 1000;
    j["fort.size"] = 50;

    j["robotFactory.type"] = BuildType::ROBOTF;
    j["robotFactory.healthPercent"] = 1000;
    j["robotFactory.size"] = 50;

    j["vehicleFactory.type"] = BuildType::VEHICLEF;
    j["vehicleFactory.healthPercent"] = 1000;
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
    j["asphaltedBridgeObject.healthPercent"] = 1000;
    j["asphaltedBridgeObject.size"] = 50;

    j["rockObject.type"] = TerrainObjectType::ROCK;
    j["rockObject.passable"] = false;
    j["rockObject.healthPercent"] = 1000;
    j["rockObject.size"] = 50;

    j["woodenBridgeObject.type"] = TerrainObjectType::_WOODENBRIDGE;
    j["woodenBridgeObject.passable"] = true;
    j["woodenBridgeObject.healthPercent"] = 10;
    j["woodenBridgeObject.size"] = 50;

    j["iceRockObject.type"] = TerrainObjectType::ICEROCK;
    j["iceRockObject.passable"] = false;
    j["iceRockObject.healthPercent"] = 1000;
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
