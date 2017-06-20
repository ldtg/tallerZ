#include "VistasFactory.h"
#include "VehicleView.h"
#include "RobotView.h"
#include <random>
#include <iostream>

ObjectMapaVista* VistasFactory::getTerrainVista(TerrainType type,
                                                Position &pos) {
  std::string path = "../src/view/images/terrain/";
  std::string type_s;

  switch (type) {
    case LAND: type_s = "land"; break;
    case PRAIRIE: type_s = "prairie"; break;
    case SNOW: type_s = "snow"; break;
    case WATER: type_s = "water"; break;
    case SWAMP: type_s = "swamp"; break;
    case LAVA: type_s = "lava"; break;
    case ROAD: type_s = "road"; break;
    case ASPHALTEDROAD: type_s = "asphaltedroad"; break;
    case WOODENBRIDGE: type_s = "woodenbridge"; break;
    case ASPHALTEDBRIDGE: type_s = "asphaltedbridge"; break;
    default: return nullptr;
  }

  path = path + type_s + ".png";
  Image *terrainVista = new Image(path.c_str());
  terrainVista->setPos(pos);
  return terrainVista;
}

int getRandomNumInRange(const int range_from, const int range_to) {
  std::random_device rand_dev;
  std::mt19937 generator(rand_dev());
  std::uniform_int_distribution<int> distr(range_from, range_to);
  return distr(generator);
}

UnitView* VistasFactory::getUnitView(UnitType type,
                                   std::string &color,
                                   std::string &action,
                                   std::string &rotation,
                                   const Position &pos) {
  if (type == R_GRUNT || type == R_TOUGH || type == R_PYRO
      || type == R_LASER || type == R_PSYCHO || type == R_SNIPER) {
    return new RobotView(type, color, pos,
                             action, rotation);
  }
  else if (type == V_JEEP || type == V_LTANK || type == V_MTANK
      || type == V_HTANK || type == V_MML) {
    return new VehicleView(type, color, pos,
                                action, rotation);
  }
  else {
    return nullptr;
  }
}

Sprite* VistasFactory::getUnitVista(UnitType type, std::string &color,
                                    std::string &action, std::string &rotation,
                                    const Position &pos) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  int despX=0, despY=0;
  float scaleW=1.3, scaleH=1.3;

  std::string path = "../src/view/images/units/";

  if (type == R_GRUNT || type == R_TOUGH || type == R_PYRO ||
      type == R_LASER || type == R_PSYCHO || type == R_SNIPER) {
    type_s = "robots";
    despX=8; despY=8;

    if (action == "walk") {
      num_frames = 4; speed = 2*num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "look_around") {
      num_frames = 3; speed = 6*num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "fire") {
      std::string robot;
      if (type == R_GRUNT) {
        robot = "grunt";
        num_frames = 5; speed = 1*num_frames;
        num_frame_return_cycle = 3;
      }
      else if (type == R_TOUGH) {
        robot = "tough";
        num_frames = 3; speed = 8;
        num_frame_return_cycle = 0;
      }
      else if (type == R_PYRO) {
        robot = "pyro";
        num_frames = 3; speed = 2*num_frames;
        num_frame_return_cycle = 1;
      }
      else if (type == R_LASER) {
        robot = "laser";
        num_frames = 3; speed = 2*num_frames;
        num_frame_return_cycle = 0;
      }
      else if (type == R_PSYCHO) {
        robot = "psycho";
        num_frames = 2; speed = 2*num_frames;
        num_frame_return_cycle = 0;
      }
      else if (type == R_SNIPER) {
        robot = "sniper";
        num_frames = 5; speed = 1*num_frames;
        num_frame_return_cycle = 3;
      }
      path = path + type_s + "/" + action + "/" + robot + "/"
          + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "create") {
      num_frames = 12; speed = 4;
      num_frame_return_cycle = 10;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_n";
    }
    else if (action == "die") {
      // Se elije una muerte al azar.
      int num_die = getRandomNumInRange(1,5);
      action = action + std::to_string(num_die);

      if (num_die == 1) {
        num_frames = 10; speed = 12;
      }
      else if (num_die == 2) {
        num_frames = 10; speed = 12;
      }
      else if (num_die == 3) {
        num_frames = 10; speed = 12;
      }
      else if (num_die == 4) {
        num_frames = 8; speed = 12;
      }
      else if (num_die == 5) {
        num_frames = 33; speed = 6;
      }
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_n";
    }
  }
  else if (type == V_JEEP) {
    type_s = "vehicles/jeep";
    despX=15; despY=20;

    if (action == "walk") {
      num_frames = 2; speed = 3*num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "look_around") {
      num_frames = 2; speed = 3*num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "fire") {
      num_frames = 2; speed = 2*num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "die") {
      num_frames = 13; speed = 1*num_frames;
      despX = 8, despY = 18;
      path = path + type_s + "/" + action + "/" + action + "_n";
    } else if (action == "create") {
      num_frames = 2; speed = 3*num_frames;
      path = path + type_s + "/" + "look_around"
          + "/" + "look_around" + "_" + color + "_r" + rotation + "_n";
    }
  }
  else if (type == V_LTANK) {
    type_s = "vehicles/light";
    despX=18; despY=18;

    if (action == "walk") {
      num_frames = 3; speed = 2*num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "look_around") {
      num_frames = 1; speed = 1;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "fire") {
      num_frames = 1; speed = 1;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "die") {
      num_frames = 8; speed = 12;
      path = path + type_s + "/" + action + "/" + action + "_n";
    } else if (action == "create") {
      num_frames = 1; speed = 1;
      path = path + type_s + "/" + "look_around"
          + "/" + "look_around" + "_" + color + "_r" + rotation + "_n";
    }
  }
  else {
    return nullptr;
  }

  Sprite *unitVista = new Sprite(path.c_str(), num_frames, speed,
                               num_frame_return_cycle, color, despX, despY);
  unitVista->setPos(pos);
  unitVista->scale(scaleW, scaleH);
  return unitVista;
}

Sprite* VistasFactory::getVehicleTopVista(UnitType type,
                                          std::string &color,
                                          const Position &pos) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  int despX=0, despY=0;
  float scaleW=1.3, scaleH=1.3;
  std::string path = "../src/view/images/units/vehicles/";

  switch (type) {
    case V_LTANK: {
      type_s = "light";
      num_frames=8; speed=40;
      num_frame_return_cycle=0;
      despX=2, despY=4;
      break;
    }
    default: return nullptr;
  }

  path = path + type_s + "/" + "top_n";
  Sprite *top = new Sprite(path.c_str(), num_frames, speed,
                           num_frame_return_cycle, color, despX, despY);
  top->setPos(pos);
  top->scale(scaleW, scaleH);
  return top;
}

Sprite* VistasFactory::getVehicleTopStillVista(UnitType type,
                                               std::string &color,
                                               const std::string &rotation,
                                               const Position &pos) {
  std::string type_s;
  int num_frames=1, speed=1, num_frame_return_cycle=0;
  int despX=0, despY=0;
  float scaleW=1.3, scaleH=1.3;
  std::string path = "../src/view/images/units/vehicles/";

  switch (type) {
    case V_LTANK: {
      type_s = "light";
      despX=2, despY=4;
      break;
    }
    default: return nullptr;
  }

  path = path + type_s + "/" + "top_r" + rotation + "_n";
  Sprite *top = new Sprite(path.c_str(), num_frames, speed,
                           num_frame_return_cycle, color, despX, despY);
  top->setPos(pos);
  top->scale(scaleW, scaleH);
  return top;
}

Image* VistasFactory::getBuildVista(BuildType type,
                                    std::string &state,
                                    Position &pos) {
  std::string type_s;
  std::string path = "../src/view/images/buildings/";
  float scaleW=1.5, scaleH=1.5;

  switch (type) {
    case FORT: type_s = "fort"; break;
    case ROBOTF: type_s = "robot"; break;
    case VEHICLEF: type_s = "vehicle"; break;
    default: return nullptr;
  }

  path = path + type_s + "/" + type_s + state + ".png";
  Image *buildVista = new Image(path.c_str());
  buildVista->setPos(pos);
  buildVista->scale(scaleW, scaleH);
  return buildVista;
}

Sprite* VistasFactory::getFlagsVista(std::string &color, Position &pos) {
  int num_frames=4, speed=6, num_frame_return_cycle=0;
  long despX = 0, despY = 0;

  std::string path = "../src/view/images/flags/flag_" + color + "_n";
  Sprite *flagVista = new Sprite(path.c_str(), num_frames, speed, num_frame_return_cycle);
  flagVista->setPos(pos.sub(despX, despY));
  return flagVista;
}

ObjectMapaVista* VistasFactory::getTerrainObjectVista(TerrainObjectType type,
                                                      std::string &state,
                                                      Position &pos) {
  std::string path = "../src/view/images/terrain/";
  std::string type_s;

  switch (type) {
    case ROCK: type_s = "rocks_jungle"; break;
    case ICEROCK: type_s = "rocks_artic"; break;
    case _WOODENBRIDGE: type_s = "woodenbridge"; break;
    case _ASPHALTEDBRIDGE: type_s = "asphaltedbridge"; break;
    default: return nullptr;
  }

  path = path + type_s + state + ".png";
  Image *terrainObjVista = new Image(path.c_str());
  terrainObjVista->setPos(pos.sub(50,50));
  return terrainObjVista;
}

Sprite* VistasFactory::getBulletVista(WeaponType type,
                                      std::string &rotation,
                                      const Position &pos) {
  long despX=0, despY=0;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  std::string path = "../src/view/images/bullet/";

  switch (type) {
    case ROCKET: {
      num_frames = 1, speed = 1, num_frame_return_cycle = 0;
      path = path + "rocket_r" + rotation + "_n";
      break;
    }
    case FIRE: {
      num_frames = 4, speed = 1, num_frame_return_cycle = 0;
//    despX = 8; despY = 8;
      path = path + "fire_r" + rotation + "_n";
      break;
    }
    case BULLET: {
      num_frames = 1, speed = 1, num_frame_return_cycle = 0;
      path = path + "bullet_r" + rotation + "_n";
      break;
    }
    case HCBULLET: {
      num_frames = 1, speed = 1, num_frame_return_cycle = 0;
      path = path + "hcbullet_r" + rotation + "_n";
      break;
    }
    case LASER: {
      num_frames = 2, speed = 1, num_frame_return_cycle = 0;
      path = path + "laser_r" + rotation + "_n";
      break;
    }
    default: return nullptr;
  }

  Sprite *bulletVista = new Sprite(path.c_str(), num_frames,
                                   speed, num_frame_return_cycle);
  bulletVista->setPos(pos.sub(despX, despY));
  return bulletVista;
}

Sprite* VistasFactory::getBulletHitVista(WeaponType type, Position &pos) {
  int num_frames, speed, num_frame_return_cycle;
  long despX, despY;
  std::string path = "../src/view/images/effects/";

  switch (type) {
    case ROCKET:
      num_frames = 12; speed = 6; num_frame_return_cycle = 0;
      despX = 8; despY = 18;
      path = path + "explosion/tank_missile_explosion1_n";
      break;
    case HCBULLET:
      num_frames = 7; speed = 4; num_frame_return_cycle = 0;
      despX = 0; despY = 0;
      path = path + "explosion/side_explosion_n";
      break;
    case FIRE:
      num_frames = 4, speed = 4, num_frame_return_cycle = 0;
      despX = 0; despY = 0;
      path = path + "fire/fire2_n";
      break;
    case LASER:
      num_frames = 3, speed = 3, num_frame_return_cycle = 0;
      despX = 0; despY = 0;
      path = path + "explosion/laser_n";
      break;
    default: return nullptr;
  }

  Sprite *hitVista = new Sprite(path.c_str(), num_frames,
                                speed, num_frame_return_cycle);
  hitVista->setPos(pos.sub(despX, despY));
  return hitVista;
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
  else if (type == SIDE_EXPLOSION) {
    type_s = "explosion";
    num_frames = 7;
    speed = 6;
    num_frame_return_cycle = 0;
    path = path + type_s + "/side_explosion_n";
  }
  else if (type == BIG_SMOKE) {
    type_s = "smoke";
    num_frames = 4;
    speed = 6;
    num_frame_return_cycle = 0;
    path = path + type_s + "/big_smoke_n";
  }
  else if (type == FIRE_SMOKE) {
    type_s = "smoke";
    num_frames = 4;
    speed = 6;
    num_frame_return_cycle = 0;
    path = path + type_s + "/small_fire_smoke_n";
  }
  else if (type == FIRE_EFFECT) {
    type_s = "fire";
    num_frames = 6;
    speed = 6;
    num_frame_return_cycle = 0;
    path = path + type_s + "/fire_n";
  }
  else {
    return nullptr;
  }

  return new Sprite(path.c_str(), num_frames,speed, num_frame_return_cycle);
}
