//
// Created by darius on 18/06/17.
//

#ifndef TALLERZ_SERVIDOR_JSON_TO_DATA_H
#define TALLERZ_SERVIDOR_JSON_TO_DATA_H

#include <json.hpp>
#include <server/model/Data.h>
#include <fstream>
#include <Exceptions/Storage_Exceptions/Storage_Exception.h>

using nlohmann::json;

class Json_to_Data {
 private:
  Data data;
  json j;
  std::ifstream json_file;
  const std::string& file_path = "data.json";


 public:

  Json_to_Data(){
    open_file();
  }

  Data load_file(){
    json_file >> this->j;

    data.ticksPerSec = j["ticksPerSec"];
    data.playerInitialTerritories = j["playerInitialTerritories"];
    data.playerInitialUnits = j["playerInitialUnits"];
    data.defaultDriver = j["defaultDriver"];
    data.rangeMultipliquer = j["rangeMultipliquer"];

    data.bullet.type = (WeaponType)j["bullet.type"];
    data.bullet.damage = j["bullet.damage"];
    data.bullet.isExplosive = j["bullet.isExplosive"];
    data.bullet.speed = j["bullet.speed"];

    data.rocket.type = (WeaponType)j["rocket.type"];
    data.rocket.damage = j["rocket.damage"];
    data.rocket.isExplosive = j["rocket.isExplosive"];
    data.rocket.speed = j["rocket.speed"];

    data.flamethrower.type = (WeaponType )j["flamethrower.type"];
    data.flamethrower.damage = j["flamethrower.damage"];
    data.flamethrower.isExplosive = j["flamethrower.isExplosive"];
    data.flamethrower.speed = j["flamethrower.speed"];

    data.r_grunt.type = (UnitType )j["r_grunt.type"];
    data.r_grunt.weapon = get_weapon((WeaponType )j["r_grunt.weapon"]);
    data.r_grunt.secsUntilFire = j["r_grunt.secsUntilFire"];
    data.r_grunt.health = j["r_grunt.health"];
    data.r_grunt.range = j["r_grunt.range"];
    data.r_grunt.speed = j["r_grunt.speed"];
    data.r_grunt.factoryRate = j["r_grunt.factoryRate"];
    data.r_grunt.factoryBaseTimeInSec = j["r_grunt.factoryBaseTimeInSec"];
    data.r_grunt.factoryMinimunTechLevel = j["r_grunt.factoryMinimunTechLevel"];

    data.r_tough.type = (UnitType )j["r_tough.type"];
    data.r_tough.weapon = get_weapon((WeaponType )j["r_tough.weapon"]);
    data.r_tough.secsUntilFire = j["r_tough.secsUntilFire"];
    data.r_tough.health = j["r_tough.health"];
    data.r_tough.range = j["r_tough.range"];
    data.r_tough.speed = j["r_tough.speed"];
    data.r_tough.factoryRate = j["r_tough.factoryRate"];
    data.r_tough.factoryBaseTimeInSec = j["r_tough.factoryBaseTimeInSec"];
    data.r_tough.factoryMinimunTechLevel = j["r_tough.factoryMinimunTechLevel"];

    data.r_pyro.type = (UnitType )j["r_pyro.type"];
    data.r_pyro.weapon = get_weapon((WeaponType )j["r_pyro.weapon"]);
    data.r_pyro.secsUntilFire = j["r_pyro.secsUntilFire"];
    data.r_pyro.health = j["r_pyro.health"];
    data.r_pyro.range = j["r_pyro.range"];
    data.r_pyro.speed = j["r_pyro.speed"];
    data.r_pyro.factoryRate = j["r_pyro.factoryRate"];
    data.r_pyro.factoryBaseTimeInSec = j["r_pyro.factoryBaseTimeInSec"];
    data.r_pyro.factoryMinimunTechLevel = j["r_pyro.factoryMinimunTechLevel"];

    data.v_jeep.type = (UnitType )j["v_jeep.type"];
    data.v_jeep.weapon = get_weapon((WeaponType )j["v_jeep.weapon"]);
    data.v_jeep.secsUntilFire = j["v_jeep.secsUntilFire"];
    data.v_jeep.health = j["v_jeep.health"];
    data.v_jeep.range = j["v_jeep.range"];
    data.v_jeep.speed = j["v_jeep.speed"];
    data.v_jeep.factoryRate = j["v_jeep.factoryRate"];
    data.v_jeep.factoryBaseTimeInSec = j["v_jeep.factoryBaseTimeInSec"];
    data.v_jeep.factoryMinimunTechLevel = j["v_jeep.factoryMinimunTechLevel"];

    data.fort.type = (BuildType )j["fort.type"];
    data.fort.health = j["fort.health"];
    data.fort.size = j["fort.size"];

    data.robotFactory.type = (BuildType )j["robotFactory.type"];
    data.robotFactory.health = 1000;
    data.robotFactory.size = 50;

    data.vehicleFactory.type = (BuildType )j["vehicleFactory.type"];
    data.vehicleFactory.health = j["vehicleFactory.health"];
    data.vehicleFactory.size = j["vehicleFactory.size"];

    data.land.type = (TerrainType) j["land.type"];
    data.land.terrainFactor = j["land.terrainFactor"];
    data.prairie.type = (TerrainType )j["prairie.type"];
    data.prairie.terrainFactor = j["prairie.terrainFactor"];
    data.snow.type = (TerrainType )j["snow.type"];
    data.snow.terrainFactor = j["snow.terrainFactor"];
    data.water.type = (TerrainType )j["water.type"];
    data.water.terrainFactor = j["water.terrainFactor"];
    data.swamp.type = (TerrainType )j["swamp.type"];
    data.swamp.terrainFactor = j["swamp.terrainFactor"];
    data.road.type = (TerrainType )j["road.type"];
    data.road.terrainFactor = j["road.terrainFactor"];
    data.asphaltedRoad.type = (TerrainType)j["asphaltedRoad.type"];
    data.asphaltedRoad.terrainFactor = j["asphaltedRoad.terrainFactor"];
    data.lava.type = (TerrainType)j["lava.type"];
    data.lava.terrainFactor = j["lava.terrainFactor"];

    data.asphaltedBridgeTerrain.type = (TerrainType )j["asphaltedBridgeTerrain.type"];
    data.asphaltedBridgeTerrain.terrainFactor = j["asphaltedBridgeTerrain.terrainFactor"];
    data.woodenBridge.type = (TerrainType) j["woodenBridge.type"];
    data.woodenBridge.terrainFactor = j["woodenBridge.terrainFactor"];

    data.asphaltedBridgeObject.type = (TerrainObjectType)j["asphaltedBridgeObject.type"];
    data.asphaltedBridgeObject.passable = j["asphaltedBridgeObject.passable"];
    data.asphaltedBridgeObject.health = j["asphaltedBridgeObject.health"];
    data.asphaltedBridgeObject.size = j["asphaltedBridgeObject.size"];
    data.rockObject.type = (TerrainObjectType )j["rockObject.type"];
    data.rockObject.passable = j["rockObject.passable"];
    data.rockObject.health = j["rockObject.health"];
    data.rockObject.size = j["rockObject.size"];
    data.woodenBridgeObject.type = (TerrainObjectType )j["woodenBridgeObject.type"];
    data.woodenBridgeObject.passable = j["woodenBridgeObject.passable"];
    data.woodenBridgeObject.health = j["woodenBridgeObject.health"];
    data.woodenBridgeObject.size = j["woodenBridgeObject.size"];
    data.iceRockObject.type = (TerrainObjectType )j["iceRockObject.type"];
    data.iceRockObject.passable = j["iceRockObject.passable"];
    data.iceRockObject.health = j["iceRockObject.health"];
    data.iceRockObject.size = j["iceRockObject.size"];

    return this->data;
  }

  Weapon& get_weapon(const WeaponType& weaponType){
    switch (weaponType){
      case (WeaponType::BULLET):
        return this->data.bullet;
      case (WeaponType::FIRE):
        return this->data.flamethrower;
      case (WeaponType::ROCKET):
        return this->data.rocket;
      case (WeaponType::HCBULLET):
        return this->data.sniperBullet;
      case (WeaponType::LASER):
        return this->data.laser;
    }
  }
  void open_file(){
    try {
      this->json_file.open(this->file_path);
    } catch (const std::exception &e) {
      throw Storage_Exception(
          "Error en la apertura del archivo %s de donde se iba a cargar la "
              "variable Data\n: %s\n", this->file_path.c_str(), e.what());
    }
  }

  void close_file(){
    try {
      this->json_file.close();
    } catch (const std::exception &e) {
      throw Storage_Exception(
          "Error el metodo close_file de Json_to_Data al cerrar el archivo "
              "%s: %s\n", this->file_path, e.what());
    }
  }
};

#endif //TALLERZ_SERVIDOR_JSON_TO_DATA_H
