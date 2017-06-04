#include "VistasFactory.h"
#include "Image.h"
#include <random>

ObjectMapaVista* VistasFactory::getTerrainVista(TerrainType type) {
  if (type == LAND) {
    return new Image("../src/view/images/terrain/land.png");
  }
  else {
    return nullptr;
  }
}

int getRandomNumInRange(const int range_from, const int range_to) {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<int> distr(range_from, range_to);
  return distr(generator);
}

Sprite* VistasFactory::getUnitVista(UnitType type,
                                    std::string &color,
                                    std::string &action,
                                    std::string &rotation) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;

  std::string path = "../src/view/images/units/";

  if (type == R_GRUNT || type == R_TOUGH) {
    type_s = "robots";
    if (action == "walk") {
      num_frames = 4;
      speed = 3 * num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "look_around") {
      num_frames = 3;
      speed = 6*num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "fire") {
      std::string robot;
      if (type == R_GRUNT) {
        robot = "grunt";
        num_frames = 5;
        speed = 1*num_frames;
        num_frame_return_cycle = 3;
      }
      else if (type == R_TOUGH) {
        robot = "tough";
        num_frames = 3;
        speed = 7*num_frames;
        num_frame_return_cycle = 0;
      }
      path = path + type_s + "/" + action + "/" + robot + "/"
          + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "create") {
      num_frames = 12;
      speed = 6;
      num_frame_return_cycle = 10;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_n";
    }
    else if (action == "die") {
      // Se elije una muerte al azar.
      int num_die = getRandomNumInRange(1,5);
      action = action + std::to_string(num_die);

//      printf("%d\n", num_die);

      if (num_die == 1) {
        num_frames = 10;
        speed = 12;
      }
      else if (num_die == 2) {
        num_frames = 10;
        speed = 12;
      }
      else if (num_die == 3) {
        num_frames = 10;
        speed = 12;
      }
      else if (num_die == 4) {
        num_frames = 8;
        speed = 12;
      }
      else if (num_die == 5) {
        num_frames = 33;
        speed = 6;
      }

      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_n";
    }
  }
  else if (type == V_JEEP) {
    type_s = "vehicles/jeep";
    if (action == "walk") {
      num_frames = 2;
      speed = 3 * num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "look_around") {
      num_frames = 2;
      speed = 3 * num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "fire") {
      num_frames = 2;
      speed = 2 * num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "die") {
      num_frames = 6;
      speed = 2 * num_frames;
      path = path + type_s + "/" + action + "/" + action + "_n";
    }
  }
  else {
    return nullptr;
  }

//  std::string path = "../src/view/images/units/" + type_s + "/" + action
//      + "/" + action + "_blue_r" + rotation + "_n";

  return new Sprite(path.c_str(), num_frames, speed, num_frame_return_cycle, color);
}

ObjectMapaVista* VistasFactory::getBuildVista(BuildType type, std::string &state) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  std::string path = "../src/view/images/buildings/";

  if (type == FORT) {
    type_s = "fort";
    if (state == "") {
      path = path + type_s + "/fort_jungle_front"
          + state + ".png";
      return new Image(path.c_str());
    }
    else if (state == "destroyed") {
      num_frames = 4;
      speed = 20;
      num_frame_return_cycle = 0;
      path = path + type_s + "/fort_jungle_front_"
          + state + "_n";
      return new Sprite(path.c_str(), num_frames, speed, num_frame_return_cycle);
    }
  }
  else {
    return nullptr;
  }
}

ObjectMapaVista* VistasFactory::getBulletVista(WeaponType type, std::string &rotation) {
  if (type == ROCKET) {
    std::string path = "../src/view/images/bullet/bullet_r" + rotation + ".png";
    return new Image(path.c_str());
  }
  else {
    return nullptr;
  }
}

Sprite* VistasFactory::getEffectVista(EffectType type) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  std::string path = "../src/view/images/effects/";

  if (type == TANK_MISSILE) {
    type_s = "explosion";
      num_frames = 12;
      speed = 6;
      num_frame_return_cycle = 0;
      path = path + type_s + "/tank_missile_explosion1_n";
  }
  else {
    return nullptr;
  }

  return new Sprite(path.c_str(), num_frames,speed, num_frame_return_cycle);
}
