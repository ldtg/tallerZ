#include "SoundsFactory.h"

Sound* SoundsFactory::getBulletFireSound(WeaponType type) {
  std::string path = "../src/view/sounds/";
  std::string type_s;

  switch (type) {
    case BULLET: type_s = "bullet_fire";break;
    case ROCKET: type_s = "rocket_fire";break;
    case FIRE: type_s = "fire_fire";break;
    case LASER: type_s = "laser_fire";break;
    case HCBULLET: type_s = "hcbullet_fire";break;
    default: return nullptr;
  }
  path = path + type_s + ".wav";
  return new Sound(path, 0);
}

Sound* SoundsFactory::getBulletHitSound(WeaponType type) {
  std::string path = "../src/view/sounds/";
  std::string type_s;

  switch (type) {
    case BULLET: type_s = "bullet_hit";break;
    case ROCKET: type_s = "rocket_hit";break;
    case HCBULLET: type_s = "hcbullet_hit";break;
    default: return nullptr;
  }
  path = path + type_s + ".wav";
  return new Sound(path, 0);
}

Sound* SoundsFactory::getUnitCreateSound(UnitType type) {
  std::string path = "../src/view/sounds/";
  std::string type_s;

  switch (type) {
    case R_GRUNT: type_s = "robot_manufactured";break;
    case R_TOUGH: type_s = "robot_manufactured";break;
    case R_PSYCHO: type_s = "robot_manufactured";break;
    case R_SNIPER: type_s = "robot_manufactured";break;
    case R_LASER: type_s = "robot_manufactured";break;
    case R_PYRO: type_s = "robot_manufactured";break;
    case V_JEEP: type_s = "vehicle_manufactured";break;
    case V_MTANK: type_s = "vehicle_manufactured";break;
    case V_LTANK: type_s = "vehicle_manufactured";break;
    case V_HTANK: type_s = "vehicle_manufactured";break;
    case V_MML: type_s = "vehicle_manufactured";break;
    default: return nullptr;
  }
  path = path + type_s + ".wav";
  return new Sound(path, 0);
}

Sound* SoundsFactory::getCapturedSound(CapturableType type) {
  std::string path = "../src/view/sounds/";
  std::string type_s;

  switch (type) {
    case UNIT: type_s = "vehicle_captured";break;
    case FLAG: type_s = "territory_taken";break;
    default: return nullptr;
  }
  path = path + type_s + ".wav";
  return new Sound(path, 0);
}

Sound* SoundsFactory::getBuildDestroyedSound() {
  std::string path = "../src/view/sounds/";
  std::string type_s = "build_destroyed";
  path = path + type_s + ".wav";
  return new Sound(path, 0);
}

Sound* SoundsFactory::getTargetDestroyedSound() {
  std::string path = "../src/view/sounds/";
  std::string type_s = "target_destroyed";
  path = path + type_s + ".wav";
  return new Sound(path, 0);
}
