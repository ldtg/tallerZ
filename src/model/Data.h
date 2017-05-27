#ifndef TALLERZ_DATA_H
#define TALLERZ_DATA_H

#include <cmath>
#include "Weapon.h"
#include "UnitData.h"
#include "TerrainData.h"
#include "BuildType.h"
#include "BuildData.h"

struct Data {
 public:
  unsigned short ticksPerSec;
  unsigned long miliSecsPerTick;
  UnitType defaultDriver;

  Weapon bullet;
  Weapon flamethrower;
  Weapon sniperBullet;
  Weapon laser;
  Weapon rocket;

  UnitData grunt;
  UnitData tough;
  UnitData jeep;

  BuildData fort;
  BuildData robotFactory;
  BuildData vehicleFactory;

  TerrainData land;
  TerrainData water;
  TerrainData lava;
  TerrainData road;

  Data() {
    ticksPerSec = 40;
    miliSecsPerTick =
        (unsigned long) std::lround((1 / (float) ticksPerSec) * 1000);
    defaultDriver = R_GRUNT;
    bullet.type = WeaponType::BULLET;
    bullet.damage = 2;
    bullet.isExplosive = false;
    bullet.speed = 0; //llega instantaneamente
    rocket.type = WeaponType::ROCKET;
    rocket.damage = 25;
    rocket.isExplosive = true;
    rocket.speed = 13; // 12 es la veloc max del vehiculo mas rapido creo

    grunt.type = UnitType::R_GRUNT;
    grunt.weapon = bullet;
    grunt.ticksUntilFire = getTickAmount(0.5);
    grunt.health = 60;
    grunt.range = 7;
    grunt.speed = 4;
    grunt.factoryRate = 3;
    grunt.factoryBaseTimeInSec = 575;
    grunt.factoryMinimunTechLevel = 1;

    tough.type = UnitType::R_TOUGH;
    tough.weapon = rocket;
    tough.ticksUntilFire = getTickAmount(0.5);
    tough.health = 300;
    tough.range = 5;
    tough.speed = 4;
    tough.factoryRate = 2;
    tough.factoryBaseTimeInSec = 42;//742
    tough.factoryMinimunTechLevel = 2;

    jeep.type = UnitType::V_JEEP;
    jeep.weapon = bullet;
    jeep.ticksUntilFire = getTickAmount(0.17);//1/6
    jeep.health = 60;
    jeep.range = 6;
    jeep.speed = 8;
    jeep.factoryRate = 1;
    jeep.factoryBaseTimeInSec = 660;
    jeep.factoryMinimunTechLevel = 1;

    fort.type = BuildType::FORT;
    fort.health = 1000;
    fort.size = 50;

    robotFactory.type = BuildType::ROBOTF;
    robotFactory.health = 1000;
    robotFactory.size = 50;

    vehicleFactory.type = BuildType::VEHICLEF;
    vehicleFactory.health = 1000;
    vehicleFactory.size = 50;

    land.type = TerrainType::LAND;
    land.terrainFactor = 1;
    water.type = TerrainType::WATER;
    water.terrainFactor = 0.7;
    road.type = TerrainType::ROAD;
    road.terrainFactor = 1.5;
    lava.type = TerrainType::LAVA;
    lava.terrainFactor = 0.1; //no importa el valor
  }
  UnitData getData(UnitType type) {
    switch (type) {
      case R_GRUNT:return grunt;
      case V_JEEP:return jeep;
      case R_TOUGH: return tough;
    }
  }
  BuildData getData(BuildType type) {
    switch (type) {
      case FORT:return fort; //MAIAMEEEEEEEE
      case BuildType::ROBOTF : return robotFactory;
      case BuildType::VEHICLEF : return vehicleFactory;
      default:return fort;//nunca deberia llegar
    }
  }
  std::vector<UnitType> getFabUnits(const BuildType &buildType,
                                    unsigned short techLevel) {
    std::vector<UnitType> aux;
    switch (buildType) {
      case FORT: {
        aux.push_back(UnitType::R_GRUNT);
        aux.push_back(UnitType::V_JEEP);
        if (techLevel > 1)
          aux.push_back(UnitType::R_TOUGH);
        break;
      }
      case ROBOTF: {
        aux.push_back(UnitType::R_GRUNT);
        if (techLevel > 1)
          aux.push_back(UnitType::R_TOUGH);
      }
      case VEHICLEF: {
        aux.push_back(UnitType::V_JEEP);
      }
    }
    return aux;
  }
  unsigned short getTickAmount(float secs) {
    return (unsigned short) std::lround(secs * ticksPerSec);
  }
  unsigned short ticksToSec(unsigned short ticks) {
    return (unsigned short) std::lround(ticks / ticksPerSec);
  }
};
extern Data data;
#endif //TALLERZ_DATA_H
