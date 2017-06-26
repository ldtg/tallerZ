#include "Json_to_Data.h"
#include <server/model/Data.h>

Json_to_Data::Json_to_Data(Data &data) : data(data) {
  open_file();
}
void Json_to_Data::load_file() {
  try {
    json_file >> this->j;
  } catch (const std::exception &e) {
    throw Storage_Exception(
        "Error en el parseo del archivo %s de donde se iba a cargar la "
            "variable Data\n", this->file_path.c_str());
  }

  data.ticksPerSec = j["ticksPerSec"];
  data.playerInitialTerritories = j["playerInitialTerritories"];
  data.playerInitialUnits = j["playerInitialUnits"];
  data.defaultDriver = j["defaultDriver"];
  data.rangeMultipliquer = j["rangeMultipliquer"];

  data.bullet.type = (WeaponType) j["bullet.type"];
  data.bullet.damage = j["bullet.damage"];
  data.bullet.isExplosive = j["bullet.isExplosive"];
  data.bullet.speed = j["bullet.speed"];

  data.rocket.type = (WeaponType) j["rocket.type"];
  data.rocket.damage = j["rocket.damage"];
  data.rocket.isExplosive = j["rocket.isExplosive"];
  data.rocket.speed = j["rocket.speed"];

  data.flamethrower.type = (WeaponType) j["flamethrower.type"];
  data.flamethrower.damage = j["flamethrower.damage"];
  data.flamethrower.isExplosive = j["flamethrower.isExplosive"];
  data.flamethrower.speed = j["flamethrower.speed"];

  data.laser.type = (WeaponType) j["laser.type"];
  data.laser.damage = j["laser.damage"];
  data.laser.isExplosive = j["laser.isExplosive"];
  data.laser.speed = j["laser.speed"];

  data.hcbullet.type = (WeaponType) j["hcbullet.type"];
  data.hcbullet.damage = j["hcbullet.damage"];
  data.hcbullet.isExplosive = j["hcbullet.isExplosive"];
  data.hcbullet.speed = j["hcbullet.speed"];

  data.r_grunt.type = (UnitType) j["r_grunt.type"];
  data.r_grunt.weapon = get_weapon((WeaponType) j["r_grunt.weapon"]);
  data.r_grunt.secsUntilFire = j["r_grunt.secsUntilFire"];
  data.r_grunt.health = j["r_grunt.health"];
  data.r_grunt.range = j["r_grunt.range"];
  data.r_grunt.speed = j["r_grunt.speed"];
  data.r_grunt.factoryRate = j["r_grunt.factoryRate"];
  data.r_grunt.factoryBaseTimeInSec = j["r_grunt.factoryBaseTimeInSec"];
  data.r_grunt.factoryMinimunTechLevel = j["r_grunt.factoryMinimunTechLevel"];

  data.r_tough.type = (UnitType) j["r_tough.type"];
  data.r_tough.weapon = get_weapon((WeaponType) j["r_tough.weapon"]);
  data.r_tough.secsUntilFire = j["r_tough.secsUntilFire"];
  data.r_tough.health = j["r_tough.health"];
  data.r_tough.range = j["r_tough.range"];
  data.r_tough.speed = j["r_tough.speed"];
  data.r_tough.factoryRate = j["r_tough.factoryRate"];
  data.r_tough.factoryBaseTimeInSec = j["r_tough.factoryBaseTimeInSec"];
  data.r_tough.factoryMinimunTechLevel = j["r_tough.factoryMinimunTechLevel"];

  data.r_pyro.type = (UnitType) j["r_pyro.type"];
  data.r_pyro.weapon = get_weapon((WeaponType) j["r_pyro.weapon"]);
  data.r_pyro.secsUntilFire = j["r_pyro.secsUntilFire"];
  data.r_pyro.health = j["r_pyro.health"];
  data.r_pyro.range = j["r_pyro.range"];
  data.r_pyro.speed = j["r_pyro.speed"];
  data.r_pyro.factoryRate = j["r_pyro.factoryRate"];
  data.r_pyro.factoryBaseTimeInSec = j["r_pyro.factoryBaseTimeInSec"];
  data.r_pyro.factoryMinimunTechLevel = j["r_pyro.factoryMinimunTechLevel"];

  data.r_laser.type = (UnitType) j["r_laser.type"];
  data.r_laser.weapon = get_weapon((WeaponType) j["r_laser.weapon"]);
  data.r_laser.secsUntilFire = j["r_laser.secsUntilFire"];
  data.r_laser.health = j["r_laser.health"];
  data.r_laser.range = j["r_laser.range"];
  data.r_laser.speed = j["r_laser.speed"];
  data.r_laser.factoryRate = j["r_laser.factoryRate"];
  data.r_laser.factoryBaseTimeInSec = j["r_laser.factoryBaseTimeInSec"];
  data.r_laser.factoryMinimunTechLevel = j["r_laser.factoryMinimunTechLevel"];

  data.r_psycho.type = (UnitType) j["r_psycho.type"];
  data.r_psycho.weapon = get_weapon((WeaponType) j["r_psycho.weapon"]);
  data.r_psycho.secsUntilFire = j["r_psycho.secsUntilFire"];
  data.r_psycho.health = j["r_psycho.health"];
  data.r_psycho.range = j["r_psycho.range"];
  data.r_psycho.speed = j["r_psycho.speed"];
  data.r_psycho.factoryRate = j["r_psycho.factoryRate"];
  data.r_psycho.factoryBaseTimeInSec = j["r_psycho.factoryBaseTimeInSec"];
  data.r_psycho.factoryMinimunTechLevel = j["r_psycho.factoryMinimunTechLevel"];

  data.r_sniper.type = (UnitType) j["r_sniper.type"];
  data.r_sniper.weapon = get_weapon((WeaponType) j["r_psycho.weapon"]);
  data.r_sniper.secsUntilFire = j["r_sniper.secsUntilFire"];
  data.r_sniper.health = j["r_sniper.health"];
  data.r_sniper.range = j["r_sniper.range"];
  data.r_sniper.speed = j["r_sniper.speed"];
  data.r_sniper.factoryRate = j["r_sniper.factoryRate"];
  data.r_sniper.factoryBaseTimeInSec = j["r_sniper.factoryBaseTimeInSec"];
  data.r_sniper.factoryMinimunTechLevel = j["r_sniper.factoryMinimunTechLevel"];

  data.v_jeep.type = (UnitType) j["v_jeep.type"];
  data.v_jeep.weapon = get_weapon((WeaponType) j["v_jeep.weapon"]);
  data.v_jeep.secsUntilFire = j["v_jeep.secsUntilFire"];
  data.v_jeep.health = j["v_jeep.health"];
  data.v_jeep.range = j["v_jeep.range"];
  data.v_jeep.speed = j["v_jeep.speed"];
  data.v_jeep.factoryRate = j["v_jeep.factoryRate"];
  data.v_jeep.factoryBaseTimeInSec = j["v_jeep.factoryBaseTimeInSec"];
  data.v_jeep.factoryMinimunTechLevel = j["v_jeep.factoryMinimunTechLevel"];

  data.v_ltank.type = (UnitType) j["v_ltank.type"];
  data.v_ltank.weapon = get_weapon((WeaponType) j["v_ltank.weapon"]);
  data.v_ltank.secsUntilFire = j["v_ltank.secsUntilFire"];
  data.v_ltank.health = j["v_ltank.health"];
  data.v_ltank.range = j["v_ltank.range"];
  data.v_ltank.speed = j["v_ltank.speed"];
  data.v_ltank.factoryRate = j["v_ltank.factoryRate"];
  data.v_ltank.factoryBaseTimeInSec = j["v_ltank.factoryBaseTimeInSec"];
  data.v_ltank.factoryMinimunTechLevel = j["v_ltank.factoryMinimunTechLevel"];

  data.v_mtank.type = (UnitType) j["v_mtank.type"];
  data.v_mtank.weapon = get_weapon((WeaponType) j["v_ltank.weapon"]);
  data.v_mtank.secsUntilFire = j["v_mtank.secsUntilFire"];
  data.v_mtank.health = j["v_mtank.health"];
  data.v_mtank.range = j["v_mtank.range"];
  data.v_mtank.speed = j["v_mtank.speed"];
  data.v_mtank.factoryRate = j["v_mtank.factoryRate"];
  data.v_mtank.factoryBaseTimeInSec = j["v_mtank.factoryBaseTimeInSec"];
  data.v_mtank.factoryMinimunTechLevel = j["v_mtank.factoryMinimunTechLevel"];

  data.v_htank.type = (UnitType) j["v_htank.type"];
  data.v_htank.weapon = get_weapon((WeaponType) j["v_htank.weapon"]);
  data.v_htank.secsUntilFire = j["v_htank.secsUntilFire"];
  data.v_htank.health = j["v_htank.health"];
  data.v_htank.range = j["v_htank.range"];
  data.v_htank.speed = j["v_htank.speed"];
  data.v_htank.factoryRate = j["v_htank.factoryRate"];
  data.v_htank.factoryBaseTimeInSec = j["v_htank.factoryBaseTimeInSec"];
  data.v_htank.factoryMinimunTechLevel = j["v_htank.factoryMinimunTechLevel"];

  data.v_mml.type = (UnitType) j["v_mml.type"];
  data.v_mml.weapon = get_weapon((WeaponType) j["v_mml.weapon"]);
  data.v_mml.secsUntilFire = j["v_mml.secsUntilFire"];
  data.v_mml.health = j["v_mml.health"];
  data.v_mml.range = j["v_mml.range"];
  data.v_mml.speed = j["v_mml.speed"];
  data.v_mml.factoryRate = j["v_mml.factoryRate"];
  data.v_mml.factoryBaseTimeInSec = j["v_mml.factoryBaseTimeInSec"];
  data.v_mml.factoryMinimunTechLevel = j["v_mml.factoryMinimunTechLevel"];

  data.fort.type = (BuildType) j["fort.type"];
  data.fort.health = j["fort.health"];
  data.fort.size = j["fort.size"];

  data.robotFactory.type = (BuildType) j["robotFactory.type"];
  data.robotFactory.health = 1000;
  data.robotFactory.size = 50;

  data.vehicleFactory.type = (BuildType) j["vehicleFactory.type"];
  data.vehicleFactory.health = j["vehicleFactory.health"];
  data.vehicleFactory.size = j["vehicleFactory.size"];

  data.land.type = (TerrainType) j["land.type"];
  data.land.terrainFactor = j["land.terrainFactor"];
  data.prairie.type = (TerrainType) j["prairie.type"];
  data.prairie.terrainFactor = j["prairie.terrainFactor"];
  data.snow.type = (TerrainType) j["snow.type"];
  data.snow.terrainFactor = j["snow.terrainFactor"];
  data.water.type = (TerrainType) j["water.type"];
  data.water.terrainFactor = j["water.terrainFactor"];
  data.swamp.type = (TerrainType) j["swamp.type"];
  data.swamp.terrainFactor = j["swamp.terrainFactor"];
  data.road.type = (TerrainType) j["road.type"];
  data.road.terrainFactor = j["road.terrainFactor"];
  data.asphaltedRoad.type = (TerrainType) j["asphaltedRoad.type"];
  data.asphaltedRoad.terrainFactor = j["asphaltedRoad.terrainFactor"];
  data.lava.type = (TerrainType) j["lava.type"];
  data.lava.terrainFactor = j["lava.terrainFactor"];

  data.asphaltedBridgeTerrain.type =
      (TerrainType) j["asphaltedBridgeTerrain.type"];
  data.asphaltedBridgeTerrain.terrainFactor =
      j["asphaltedBridgeTerrain.terrainFactor"];
  data.woodenBridge.type = (TerrainType) j["woodenBridge.type"];
  data.woodenBridge.terrainFactor = j["woodenBridge.terrainFactor"];

  data.asphaltedBridgeObject.type =
      (TerrainObjectType) j["asphaltedBridgeObject.type"];
  data.asphaltedBridgeObject.passable = j["asphaltedBridgeObject.passable"];
  data.asphaltedBridgeObject.health = j["asphaltedBridgeObject.health"];
  data.asphaltedBridgeObject.size = j["asphaltedBridgeObject.size"];

  data.rockObject.type = (TerrainObjectType) j["rockObject.type"];
  data.rockObject.passable = j["rockObject.passable"];
  data.rockObject.health = j["rockObject.health"];
  data.rockObject.size = j["rockObject.size"];

  data.woodenBridgeObject.type =
      (TerrainObjectType) j["woodenBridgeObject.type"];
  data.woodenBridgeObject.passable = j["woodenBridgeObject.passable"];
  data.woodenBridgeObject.health = j["woodenBridgeObject.health"];
  data.woodenBridgeObject.size = j["woodenBridgeObject.size"];

  data.iceRockObject.type = (TerrainObjectType) j["iceRockObject.type"];
  data.iceRockObject.passable = j["iceRockObject.passable"];
  data.iceRockObject.health = j["iceRockObject.health"];
  data.iceRockObject.size = j["iceRockObject.size"];
}
Weapon &Json_to_Data::get_weapon(const WeaponType &weaponType) {
  switch (weaponType) {
    case (WeaponType::BULLET):return this->data.bullet;
    case (WeaponType::FIRE):return this->data.flamethrower;
    case (WeaponType::ROCKET):return this->data.rocket;
    case (WeaponType::HCBULLET):return this->data.sniperBullet;
    case (WeaponType::LASER):return this->data.laser;
    default:return this->data.bullet;
  }
}
