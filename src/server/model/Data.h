#ifndef TALLERZ_DATA_H
#define TALLERZ_DATA_H

#include <cmath>
#include <tests/Json_to_Data.h>
#include "Weapon.h"
#include "UnitData.h"
#include "common/Map/TerrainData.h"
#include "common/Types/BuildType.h"
#include "BuildData.h"
#include "TerrainObjectData.h"

struct Data {
 public:
  unsigned short ticksPerSec;
  unsigned short rangeMultipliquer;
  unsigned long miliSecsPerTick;
  unsigned short playerInitialTerritories;
  unsigned short playerInitialUnits;
  UnitType defaultDriver;

  Weapon bullet;
  Weapon flamethrower;
  Weapon sniperBullet;
  Weapon laser;
  Weapon rocket;
  Weapon hcbullet;

  UnitData r_grunt;
  UnitData r_tough;
  UnitData r_pyro;
  UnitData r_sniper;
  UnitData r_laser;
  UnitData r_psycho;
  UnitData v_jeep;
  UnitData v_mtank;
  UnitData v_ltank;
  UnitData v_htank;
  UnitData v_mml;

  BuildData fort;
  BuildData robotFactory;
  BuildData vehicleFactory;

  TerrainData land;
  TerrainData prairie;
  TerrainData water;
  TerrainData swamp;
  TerrainData lava;
  TerrainData road;
  TerrainData snow;
  TerrainData asphaltedRoad;
  TerrainData asphaltedBridgeTerrain;
  TerrainData woodenBridge;

  TerrainObjectData asphaltedBridgeObject;
  TerrainObjectData rockObject;
  TerrainObjectData woodenBridgeObject;
  TerrainObjectData iceRockObject;

  Data(){
    Json_to_Data jtod(*this);
    jtod.load_file();
    miliSecsPerTick =
        (unsigned long) std::lround((1 / (float) ticksPerSec) * 1000);
  }
//  Data() {
//    ticksPerSec = 10;
//    miliSecsPerTick =
//        (unsigned long) std::lround((1 / (float) ticksPerSec) * 1000);
//
//    playerInitialTerritories = 1;
//    playerInitialUnits = 0;
//    defaultDriver = R_GRUNT;
//    //para aumentar el rango de las unidades
//    rangeMultipliquer = 15;
//
//    bullet.type = WeaponType::BULLET;
//    bullet.damage = 2;
//    bullet.isExplosive = false;
//    bullet.speed = 0; //llega instantaneamente
//
//    rocket.type = WeaponType::ROCKET;
//    rocket.damage = 25;
//    rocket.isExplosive = true;
//    rocket.speed = 15; // 12 es la veloc max del vehiculo mas rapido creo
//
//    flamethrower.type = WeaponType::FIRE;
//    flamethrower.damage = 10;
//    flamethrower.isExplosive = true;
//    flamethrower.speed = 15;
//
//    laser.type = WeaponType::LASER;
//    laser.damage = 10;
//    laser.isExplosive = false;
//    laser.speed = 15;
//
//    hcbullet.type = WeaponType::HCBULLET;
//    hcbullet.damage = 20;
//    hcbullet.isExplosive = true;
//    hcbullet.speed = 15;
//
//    r_grunt.type = UnitType::R_GRUNT;
//    r_grunt.weapon = bullet;
//    r_grunt.secsUntilFire = 0.5;
//    r_grunt.healthPercent = 60;
//    r_grunt.range = 7;//el rango lo aumentan solo las unidades con el range mult
//    r_grunt.speed = 4;
//    r_grunt.factoryRate = 3;
//    r_grunt.factoryBaseTimeInSec = 575;
//    r_grunt.factoryMinimunTechLevel = 1;
//
//    r_tough.type = UnitType::R_TOUGH;
//    r_tough.weapon = rocket;
//    r_tough.secsUntilFire = 0.5;
//    r_tough.healthPercent = 300;
//    r_tough.range = 5;
//    r_tough.speed = 4;
//    r_tough.factoryRate = 2;
////    r_tough.factoryBaseTimeInSec = 742;
//    r_tough.factoryBaseTimeInSec = 30;
//    r_tough.factoryMinimunTechLevel = 2;
//
//    r_pyro.type = UnitType::R_PYRO;
//    r_pyro.weapon = flamethrower;
//    r_pyro.secsUntilFire = 0.25;
//    r_pyro.healthPercent = 100;
//    r_pyro.range = 6;
//    r_pyro.speed = 4;
//    r_pyro.factoryRate = 4;
////    r_pyro.factoryBaseTimeInSec = 840;
//    r_pyro.factoryBaseTimeInSec = 30;
//    r_pyro.factoryMinimunTechLevel = 4;
//
//    r_laser.type = UnitType::R_LASER;
//    r_laser.weapon = laser;
//    r_laser.secsUntilFire = 0.25;
//    r_laser.healthPercent = 100;
//    r_laser.range = 7;
//    r_laser.speed = 4;
//    r_laser.factoryRate = 5;
////    r_laser.factoryBaseTimeInSec = 900;
//    r_laser.factoryBaseTimeInSec = 30;
//    r_laser.factoryMinimunTechLevel = 5;
//
//    r_psycho.type = UnitType::R_PSYCHO;
//    r_psycho.weapon = bullet;
//    r_psycho.secsUntilFire = 0.1;
//    r_psycho.healthPercent = 80;
//    r_psycho.range = 7;
//    r_psycho.speed = 4;
//    r_psycho.factoryRate = 3;
////    r_psycho.factoryBaseTimeInSec = 600;
//    r_psycho.factoryBaseTimeInSec = 30;
//    r_psycho.factoryMinimunTechLevel = 2;
//
//    r_sniper.type = UnitType::R_SNIPER;
//    r_sniper.weapon = bullet;
//    r_sniper.secsUntilFire = 0.25;
//    r_sniper.healthPercent = 80;
//    r_sniper.range = 10;
//    r_sniper.speed = 4;
//    r_sniper.factoryRate = 3;
////    r_sniper.factoryBaseTimeInSec = 575;
//    r_sniper.factoryBaseTimeInSec = 30;
//    r_sniper.factoryMinimunTechLevel = 3;
//
//    v_jeep.type = UnitType::V_JEEP;
//    v_jeep.weapon = bullet;
//    v_jeep.secsUntilFire = 0.17;//1/6
//    v_jeep.healthPercent = 60;
//    v_jeep.range = 6;
//    v_jeep.speed = 8;
//    v_jeep.factoryRate = 1;
//    v_jeep.factoryBaseTimeInSec = 660;
//    v_jeep.factoryMinimunTechLevel = 1;
//
//    v_ltank.type = UnitType::V_LTANK;
//    v_ltank.weapon = hcbullet;
//    v_ltank.secsUntilFire = 2;
//    v_ltank.healthPercent = 80;
//    v_ltank.range = 6;
//    v_ltank.speed = 6;
//    v_ltank.factoryRate = 1;
////    v_ltank.factoryBaseTimeInSec = 840;
//    v_ltank.factoryBaseTimeInSec = 20;
//    v_ltank.factoryMinimunTechLevel = 2;
//
//    v_mtank.type = UnitType::V_MTANK;
//    v_mtank.weapon = hcbullet;
//    v_mtank.secsUntilFire = 2;
//    v_mtank.healthPercent = 120;
//    v_mtank.range = 7;
//    v_mtank.speed = 5;
//    v_mtank.factoryRate = 1;
//    v_mtank.factoryBaseTimeInSec = 1080;
//    v_mtank.factoryMinimunTechLevel = 3;
//
//    v_htank.type = UnitType::V_HTANK;
//    v_htank.weapon = hcbullet;
//    v_htank.secsUntilFire = 2;
//    v_htank.healthPercent = 180;
//    v_htank.range = 8;
//    v_htank.speed = 5;
//    v_htank.factoryRate = 1;
//    v_htank.factoryBaseTimeInSec = 1200;
//    v_htank.factoryMinimunTechLevel = 4;
//
//    v_mml.type = UnitType::V_MML;
//    v_mml.weapon = rocket;
//    v_mml.secsUntilFire = 0.5;
//    v_mml.healthPercent = 200;
//    v_mml.range = 8;
//    v_mml.speed = 5;
//    v_mml.factoryRate = 1;
//    v_mml.factoryBaseTimeInSec = 1320;
//    v_mml.factoryMinimunTechLevel = 5;
//
//    fort.type = BuildType::FORT;
//    fort.healthPercent = 1000;
//    fort.size = 50;
//
//    robotFactory.type = BuildType::ROBOTF;
//    robotFactory.healthPercent = 1000;
//    robotFactory.size = 50;
//
//    vehicleFactory.type = BuildType::VEHICLEF;
//    vehicleFactory.healthPercent = 1000;
//    vehicleFactory.size = 50;
//
//    land.type = TerrainType::LAND;
//    land.terrainFactor = 1;
//    prairie.type = TerrainType::PRAIRIE;
//    prairie.terrainFactor = 1;
//    snow.type = TerrainType::SNOW;
//    snow.terrainFactor = 1;
//    water.type = TerrainType::WATER;
//    water.terrainFactor = 0.7;
//    swamp.type = TerrainType::SWAMP;
//    swamp.terrainFactor = 0.7;
//    road.type = TerrainType::ROAD;
//    road.terrainFactor = 2;
//    asphaltedRoad.type = TerrainType::ASPHALTEDROAD;
//    asphaltedRoad.terrainFactor = 2;
//    lava.type = TerrainType::LAVA;
//    lava.terrainFactor = 0.1; //no importa el valor
//
//    asphaltedBridgeTerrain.type = TerrainType::ASPHALTEDBRIDGE;
//    asphaltedBridgeTerrain.terrainFactor = 1;
//    woodenBridge.type = TerrainType::WOODENBRIDGE;
//    woodenBridge.terrainFactor = 1;
//
//    asphaltedBridgeObject.type = TerrainObjectType::_ASPHALTEDBRIDGE;
//    asphaltedBridgeObject.passable = true;
//    asphaltedBridgeObject.healthPercent = 1000;
//    asphaltedBridgeObject.size = 50;
//
//    rockObject.type = TerrainObjectType::ROCK;
//    rockObject.passable = false;
//    rockObject.healthPercent = 1000;
//    rockObject.size = 50;
//
//    woodenBridgeObject.type = TerrainObjectType::_WOODENBRIDGE;
//    woodenBridgeObject.passable = true;
//    woodenBridgeObject.healthPercent = 1000;
//    woodenBridgeObject.size = 50;
//
//    iceRockObject.type = TerrainObjectType::ICEROCK;
//    iceRockObject.passable = false;
//    iceRockObject.healthPercent = 1000;
//    iceRockObject.size = 50;
//  }

  UnitData getData(UnitType type) {
    switch (type) {
      case R_GRUNT:return r_grunt;
      case R_TOUGH:return r_tough;
      case R_LASER:return r_laser;
      case R_PSYCHO:return r_psycho;
      case R_PYRO:return r_pyro;
      case R_SNIPER:return r_sniper;
      case V_JEEP:return v_jeep;
      case V_LTANK:return v_ltank;
      case V_MTANK:return v_mtank;
      case V_HTANK:return v_htank;
      case V_MML:return v_mml;
      default: return r_grunt;
    }
  }
  BuildData getData(BuildType type) {
    switch (type) {
      case BuildType::FORT : return fort;
      case BuildType::ROBOTF : return robotFactory;
      case BuildType::VEHICLEF : return vehicleFactory;
      default:return fort;
    }
  }

  /**
 * get_terrain_data: Devuelve el tipo de TerrainData acorde al
 * parametro terrain que puede ser: land, prairie, water, lava,
 * swamp, road, bridge o snow.
 * @param terrain : tipo de terreno
 * @return TerrainData
 */
  TerrainData get_terrain_data(TerrainType terrain) {
    switch (terrain) {
      case PRAIRIE:return prairie;
      case ROAD:return road;
      case ASPHALTEDROAD:return asphaltedRoad;
      case WOODENBRIDGE:return woodenBridge;
      case ASPHALTEDBRIDGE:return asphaltedBridgeTerrain;
      case LAND:return land;
      case SWAMP:return swamp;
      case LAVA:return lava;
      case SNOW:return snow;
      case WATER:return water;
      default:return land;
    }
  }

  TerrainObjectData getObjectData(TerrainObjectType terrainObjectType) {
    switch (terrainObjectType) {
      case (TerrainObjectType::_WOODENBRIDGE):return woodenBridgeObject;
      case (TerrainObjectType::_ASPHALTEDBRIDGE):return asphaltedBridgeObject;
      case (TerrainObjectType::ICEROCK):return iceRockObject;
      case (TerrainObjectType::ROCK):return rockObject;
      default : return iceRockObject;
    }
  }
  std::vector<UnitType> getFabUnits(const BuildType &buildType,
                                    unsigned short techLevel) {
    std::vector<UnitType> aux;
    if (buildType == ROBOTF || buildType == FORT) {
      if (techLevel >= getData(R_GRUNT).factoryMinimunTechLevel)
        aux.push_back(R_GRUNT);
      if (techLevel >= getData(R_TOUGH).factoryMinimunTechLevel)
        aux.push_back(R_TOUGH);
      if (techLevel >= getData(R_SNIPER).factoryMinimunTechLevel)
        aux.push_back(R_SNIPER);
      if (techLevel >= getData(R_PYRO).factoryMinimunTechLevel)
        aux.push_back(R_PYRO);
      if (techLevel >= getData(R_PSYCHO).factoryMinimunTechLevel)
        aux.push_back(R_PSYCHO);
      if (techLevel >= getData(R_LASER).factoryMinimunTechLevel)
        aux.push_back(R_LASER);
    }
    if (buildType == VEHICLEF || buildType == FORT) {
      if (techLevel >= getData(V_JEEP).factoryMinimunTechLevel)
        aux.push_back(V_JEEP);
      if (techLevel >= getData(V_LTANK).factoryMinimunTechLevel)
        aux.push_back(V_LTANK);
      if (techLevel >= getData(V_MTANK).factoryMinimunTechLevel)
        aux.push_back(V_MTANK);
      if (techLevel >= getData(V_HTANK).factoryMinimunTechLevel)
        aux.push_back(V_HTANK);
      if (techLevel >= getData(V_MML).factoryMinimunTechLevel)
        aux.push_back(V_MML);
    }
    return aux;
  }
  unsigned long getTickAmount(float secs) {
    return (unsigned long) std::lround(secs * ticksPerSec);
  }
  unsigned short ticksToSec(unsigned long ticks) {
    return (unsigned short) std::lround(ticks / ticksPerSec);
  }
};
extern Data data;
#endif //TALLERZ_DATA_H
