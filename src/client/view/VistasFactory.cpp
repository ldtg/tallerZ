#include "VistasFactory.h"
#include <random>

ObjectMapaVista* VistasFactory::getTerrainVista(TerrainType type, Position &pos) {
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

Sprite* VistasFactory::getUnitVista(UnitType type, std::string &color,
                                    std::string &action, std::string &rotation,
                                    const Position &pos) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  long despX=0, despY=0;

  std::string path = "../src/view/images/units/";

  if (type == R_GRUNT || type == R_TOUGH || type == R_PYRO) {
    type_s = "robots";
    if (action == "walk") {
      num_frames = 4;
      speed = 3 * num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "look_around") {
      despX=8, despY=8;
      num_frames = 3;
      speed = 6*num_frames;
      despX = 8, despY = 8;
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
      else if (type == R_PYRO) {
        robot = "pyro";
        num_frames = 3;
        speed = 7*num_frames;
        num_frame_return_cycle = 0;
      }
      path = path + type_s + "/" + action + "/" + robot + "/"
          + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "create") {
      num_frames = 12;
      speed = 4;
      num_frame_return_cycle = 10;
      despX = 8, despY = 8;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_n";
    }
    else if (action == "die") {
      // Se elije una muerte al azar.
      int num_die = getRandomNumInRange(1,5);
      action = action + std::to_string(num_die);

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
//    despX = 0, despY = 0;

    if (action == "walk") {
      num_frames = 2;
      speed = 3 * num_frames;
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_r" + rotation + "_n";
    }
    else if (action == "look_around") {
      num_frames = 2;
      speed = 3 * num_frames;
      despX = 25, despY = 25;
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
      num_frames = 13;
      speed = 1 * num_frames;
      despX = 0, despY = 10;
      path = path + type_s + "/" + action + "/" + action + "_n";
    } else {//TODO: AGREGAR CREATEEE
      num_frames = 2;
      speed = 3 * num_frames;
      despX = 25, despY = 25;
      path = path + type_s + "/" + "look_around"
          + "/" + "look_around" + "_" + color + "_r" + rotation + "_n";
    }
  }
  else {
    return nullptr;
  }

  Sprite *unitVista = new Sprite(path.c_str(), num_frames,
                               speed, num_frame_return_cycle, color);
  unitVista->setPos(pos.sub(despX, despY));
  return unitVista;
}

ObjectMapaVista* VistasFactory::getBuildVista(BuildType type,
                                              std::string &state,
                                              Position &pos) {
  std::string type_s;
  std::string path = "../src/view/images/buildings/";

  switch (type) {
    case FORT: type_s = "fort"; break;
    case ROBOTF: type_s = "robot"; break;
    case VEHICLEF: type_s = "vehicle"; break;
    default: return nullptr;
  }

  path = path + type_s + "/" + type_s + state + ".png";
  ObjectMapaVista *buildVista = new Image(path.c_str());
  buildVista->setPos(pos);
  return buildVista;
}

/*
ObjectMapaVista* VistasFactory::getCapturableVista(CapturableType type, Position &pos) {
  ObjectMapaVista *capturableVista = nullptr;
  long despX=0, despY=0;

  switch (type) {
//    case UNIT: {
//      despX = 25, despY = 25;
//      capturableVista = new Image("../src/view/images/units/vehicles/jeep/capturable.png");
//      break;
//    }
  case FLAG: {
      std::string color("null");
      despX = 15, despY = 15;
      capturableVista = getFlagsVista(color, pos);
      break;
    } default: return nullptr;
  }
  capturableVista->setPos(pos.sub(despX, despY));
  return capturableVista;
}
*/

Sprite* VistasFactory::getFlagsVista(std::string &color, Position &pos) {
  int num_frames=4, speed=6, num_frame_return_cycle=0;
  long despX = 0, despY = 0;

  std::string path = "../src/view/images/flags/flag_" + color + "_n";
  Sprite *flagVista = new Sprite(path.c_str(), num_frames, speed, num_frame_return_cycle);
  flagVista->setPos(pos.sub(despX, despY));
  return flagVista;
}

ObjectMapaVista* VistasFactory::getTerrainObjectVista(TerrainObjectType type, Position &pos) {
  std::string path = "../src/view/images/terrain/";
  switch (type) {
    case ROCK: path = path + "rocks_jungle.png"; break;
    case ICEROCK: path = path + "rocks_artic.png"; break;
    case _WOODENBRIDGE: path = path + "woodenbridge.png"; break;
    case _ASPHALTEDBRIDGE: path = path + "asphaltedbridge.png"; break;
    default: return nullptr;
  }
  Image *terrainObjVista = new Image(path.c_str());
  terrainObjVista->setPos(pos.sub(50,50));
  return terrainObjVista;
}

ObjectMapaVista* VistasFactory::getBulletVista(WeaponType type,
                                               std::string &rotation,
                                               Position &pos) {
  long despX, despY;
  ObjectMapaVista *bulletVista = nullptr;

  if (type == ROCKET) {
    despX = 0; despY = 0;
    std::string path = "../src/view/images/bullet/bullet_r" + rotation + ".png";
    bulletVista = new Image(path.c_str());
  }
  else if (type == FIRE) {
    int num_frames=4, speed=4, num_frame_return_cycle=0;
    despX = 8; despY = 8;
    std::string path = "../src/view/images/bullet/fire_r" + rotation + "_n";
    bulletVista = new Sprite(path.c_str(), num_frames, speed, num_frame_return_cycle);
  }
  else {
    return nullptr;
  }
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
    case FIRE:
      num_frames = 4, speed = 4, num_frame_return_cycle = 0;
      despX = 0; despY = 0;
      path = path + "fire/fire2_n";
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
