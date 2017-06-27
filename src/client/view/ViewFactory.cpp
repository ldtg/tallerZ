#include "ViewFactory.h"
#include "client/view/unit/VehicleView.h"
#include "client/view/unit/RobotView.h"
#include "client/view/explosion/RocketHitView.h"
#include "client/view/explosion/HCBulletHitView.h"
#include "client/view/explosion/FireHitView.h"
#include "client/view/explosion/LaserHitView.h"
#include "client/view/building/FortView.h"
#include "client/view/building/RobotFView.h"
#include "client/view/building/VehicleFView.h"
#include <random>
#include <iostream>

Image* ViewFactory::getTerrainVista(const TerrainType &type,
                                    const Position &pos) {
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

int getRandomNumInRange(const int min, const int max) {
  return min + (rand() % (max - min + 1));
}

UnitView* ViewFactory::getUnitView(const UnitType &type,
                                   const std::string &color,
                                   std::string &action,
                                   const std::string &rotation,
                                   const Position &pos) {

  if (type == R_GRUNT || type == R_TOUGH || type == R_PYRO
      || type == R_LASER || type == R_PSYCHO || type == R_SNIPER) {
    return new RobotView(type, color, pos, action, rotation);
  }

  std::map<int, Position> pointRotView;
  std::map<int, SDL_Point> pointRotTop;
  SDL_Point p;

  if (type == V_JEEP) {
    pointRotView.emplace(0, Position(3, 16));
    pointRotView.emplace(45, Position(9, 20));
    pointRotView.emplace(90, Position(14, 23));
    pointRotView.emplace(135, Position(24, 21));
    pointRotView.emplace(180, Position(30, 15));
    pointRotView.emplace(225, Position(25, 8));
    pointRotView.emplace(270, Position(16, 8));
    pointRotView.emplace(315, Position(9, 8));

    p={3, 11};  pointRotTop.emplace(0, p);
    p={5, 11};  pointRotTop.emplace(45, p);
    p={8, 11};  pointRotTop.emplace(90, p);
    p={12, 11}; pointRotTop.emplace(135, p);
    p={13, 11}; pointRotTop.emplace(180, p);
    p={11, 7};  pointRotTop.emplace(225, p);
    p={8, 5};   pointRotTop.emplace(270, p);
    p={5, 7};   pointRotTop.emplace(315, p);
  }
  else if (type == V_LTANK) {
    pointRotView.emplace(0, Position(19, 9));
    pointRotView.emplace(180, Position(19, 9));
    pointRotView.emplace(45, Position(18, 10));
    pointRotView.emplace(225, Position(18, 10));
    pointRotView.emplace(90, Position(14, 9));
    pointRotView.emplace(270, Position(14, 9));
    pointRotView.emplace(135, Position(14, 9));
    pointRotView.emplace(315, Position(14, 9));

    p={16, 12};  pointRotTop.emplace(0, p);
    p={16, 10};  pointRotTop.emplace(45, p);
    p={16, 10};  pointRotTop.emplace(90, p);
    p={16, 10}; pointRotTop.emplace(135, p);
    p={16, 10}; pointRotTop.emplace(180, p);
    p={16, 10};  pointRotTop.emplace(225, p);
    p={16, 10};   pointRotTop.emplace(270, p);
    p={16, 12};   pointRotTop.emplace(315, p);
  }
  else if (type == V_MTANK) {
    pointRotView.emplace(0, Position(18, 2));
    pointRotView.emplace(180, Position(18, 2));
    pointRotView.emplace(45, Position(16, 6));
    pointRotView.emplace(225, Position(16, 6));
    pointRotView.emplace(90, Position(14, 0));
    pointRotView.emplace(270, Position(14, 0));
    pointRotView.emplace(135, Position(12, 6));
    pointRotView.emplace(315, Position(12, 6));

    p={12, 6};  pointRotTop.emplace(0, p);
    p={11, 4};  pointRotTop.emplace(45, p);
    p={9, 5};  pointRotTop.emplace(90, p);
    p={11, 6}; pointRotTop.emplace(135, p);
    p={14, 6}; pointRotTop.emplace(180, p);
    p={10, 6};  pointRotTop.emplace(225, p);
    p={9, 6};   pointRotTop.emplace(270, p);
    p={11, 6};   pointRotTop.emplace(315, p);
  }
  else if (type == V_HTANK) {
    pointRotView.emplace(0, Position(18, 13));
    pointRotView.emplace(180, Position(18, 13));
    pointRotView.emplace(45, Position(17, 8));
    pointRotView.emplace(225, Position(17, 8));
    pointRotView.emplace(90, Position(15, 8));
    pointRotView.emplace(270, Position(15, 8));
    pointRotView.emplace(135, Position(13, 10));
    pointRotView.emplace(315, Position(13, 10));

    p={8, 12};  pointRotTop.emplace(0, p);
    p={14, 14};  pointRotTop.emplace(45, p);
    p={16, 15};  pointRotTop.emplace(90, p);
    p={19, 14}; pointRotTop.emplace(135, p);
    p={24, 12}; pointRotTop.emplace(180, p);
    p={17, 10};  pointRotTop.emplace(225, p);
    p={16, 10};   pointRotTop.emplace(270, p);
    p={14, 10};   pointRotTop.emplace(315, p);
  }
  else if (type == V_MML) {
    pointRotView.emplace(0, Position(10, 7));
    pointRotView.emplace(45, Position(12, 16));
    pointRotView.emplace(90, Position(14, 6));
    pointRotView.emplace(135, Position(20, 10));
    pointRotView.emplace(180, Position(21, 6));
    pointRotView.emplace(225, Position(18, 9));
    pointRotView.emplace(270, Position(10, 5));
    pointRotView.emplace(315, Position(11, 7));

    p={10, 8};  pointRotTop.emplace(0, p);
    p={12, 8};  pointRotTop.emplace(45, p);
    p={11, 8};  pointRotTop.emplace(90, p);
    p={12, 10}; pointRotTop.emplace(135, p);
    p={10, 8}; pointRotTop.emplace(180, p);
    p={13, 9};  pointRotTop.emplace(225, p);
    p={11, 6};   pointRotTop.emplace(270, p);
    p={12, 12};   pointRotTop.emplace(315, p);
  }
  else {
    return nullptr;
  }

  return new VehicleView(type, color, pos, action, rotation, pointRotView, pointRotTop);
}

Sprite* ViewFactory::getUnitAnimation(const UnitType &type,
                                      const std::string &color,
                                      std::string &action,
                                      const std::string &rotation,
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
      // Se elije un look_around al azar.
      int num_look = getRandomNumInRange(1,9);
      action = action + std::to_string(num_look);

      if (num_look==1 || num_look==3 ||
          num_look==4 || num_look==5) {
        num_frames = 6; speed = 80;
      }
      else if (num_look == 2) {
        num_frames = 10; speed = 8;
      }
      else if (num_look == 6) {
        num_frames = 11; speed = 8;
      }
      else if (num_look == 7) {
        num_frames = 4; speed = 12;
      }
      else if (num_look == 8) {
        num_frames = 12; speed = 1*num_frames;
      }
      else if (num_look == 9) {
        num_frames = 11; speed = 1*num_frames;
      }
      path = path + type_s + "/" + action
          + "/" + action + "_" + color + "_n";
    }
    else if (action == "fire") {
      std::string robot;
      if (type == R_GRUNT) {
        robot = "grunt";
        num_frames = 5; speed = 7;
        num_frame_return_cycle = 3;
      }
      else if (type == R_TOUGH) {
        robot = "tough";
        num_frames = 3; speed = 10;
        num_frame_return_cycle = 1;
      }
      else if (type == R_PYRO) {
        robot = "pyro";
        num_frames = 3; speed = 2*num_frames;
        num_frame_return_cycle = 1;
      }
      else if (type == R_LASER) {
        robot = "laser";
        num_frames = 3; speed = 1*num_frames;
        num_frame_return_cycle = 0;
      }
      else if (type == R_PSYCHO) {
        robot = "psycho";
        num_frames = 2; speed = 2*num_frames;
        num_frame_return_cycle = 0;
      }
      else if (type == R_SNIPER) {
        robot = "sniper";
        num_frames = 5; speed = 4;
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
      num_frames = 1; speed = 2*num_frames;
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
  else if (type == V_MTANK) {
    type_s = "vehicles/medium";
    despX=18; despY=8;

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
  else if (type == V_HTANK) {
    type_s = "vehicles/heavy";
    despX=18; despY=14;

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
  else if (type == V_MML) {
    type_s = "vehicles/mml";
    despX=11; despY=12;

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

Sprite* ViewFactory::getVehicleTopVista(const UnitType &type,
                                        const std::string &color,
                                        const Position &pos) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  int despX=0, despY=0;
  float scaleW=1.3, scaleH=1.3;
  std::string path = "../src/view/images/units/vehicles/";

  switch (type) {
    case V_JEEP: {
      type_s = "jeep";
      num_frames=8; speed=40;
      path = path + type_s + "/" + "top_n";
      break;
    }
    case V_LTANK: {
      type_s = "light";
      num_frames=8; speed=40;
      path = path + type_s + "/" + "top_n";
      break;
    }
    case V_MTANK: {
      type_s = "medium";
      num_frames=8; speed=40;
      path = path + type_s + "/" + "top_n";
      break;
    }
    case V_HTANK: {
      type_s = "heavy";
      num_frames=8; speed=40;
      path = path + type_s + "/" + "top_" + color + "_n";
      break;
    }
    case V_MML: {
      type_s = "mml";
      num_frames=8; speed=40;
      path = path + type_s + "/" + "top_" + color + "_n";
      break;
    }
    default: return nullptr;
  }

  Sprite *top = new Sprite(path.c_str(), num_frames, speed,
                           num_frame_return_cycle, color, despX, despY);
  top->setPos(pos);
  top->scale(scaleW, scaleH);
  return top;
}

Sprite* ViewFactory::getVehicleTopFireVista(const UnitType &type,
                                            const std::string &color,
                                            const std::string &rotation,
                                            const Position &pos) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  int despX=0, despY=0;
  float scaleW=1.3, scaleH=1.3;
  std::string path = "../src/view/images/units/vehicles/";

  switch (type) {
    case V_JEEP: {
      type_s = "jeep";
      num_frames=2; speed=2*num_frames;
      path = path + type_s + "/" + "top_fire_r" + rotation + "_n";
      break;
    }
    case V_LTANK: {
      type_s = "light";
      num_frames=1; speed=1;
      path = path + type_s + "/" + "top_fire_r" + rotation + "_n";
      break;
    }
    case V_MTANK: {
      type_s = "medium";
      num_frames=1; speed=1;
      path = path + type_s + "/" + "top_fire_r" + rotation + "_n";
      break;
    }
    case V_HTANK: {
      type_s = "heavy";
      num_frames=1; speed=1;
      path = path + type_s + "/" + "top_fire_" + color + "_r" + rotation + "_n";
      break;
    }
    case V_MML: {
      type_s = "mml";
      num_frames=1; speed=1;
      path = path + type_s + "/" + "top_fire_" + color + "_r" + rotation + "_n";
      break;
    }
    default: return nullptr;
  }

  Sprite *top = new Sprite(path.c_str(), num_frames, speed,
                           num_frame_return_cycle, color, despX, despY);
  top->setPos(pos);
  top->scale(scaleW, scaleH);

  return top;
}

BuildingView* ViewFactory::getBuildingVista(const BuildType &type,
                                            const std::string &techLevel,
                                            const std::string &color,
                                            const Position &pos) {
  switch (type) {
    case FORT: return new FortView(pos, color); break;
    case ROBOTF: return new RobotFView(techLevel, pos, color); break;
    case VEHICLEF: return new VehicleFView(techLevel, pos, color); break;
    default: return nullptr;
  }
}

Image* ViewFactory::getBuildingImage(const BuildType &type,
                                     const std::string &state,
                                     const Position &pos) {
  std::string type_s;
  std::string path = "../src/view/images/buildings/";

  switch (type) {
    case FORT: type_s = "fort"; break;
    case ROBOTF: type_s = "robot"; break;
    case VEHICLEF: type_s = "vehicle"; break;
    default: return nullptr;
  }

  path = path + type_s + "/" + type_s + state + ".png";
  Image *buildVista = new Image(path.c_str());
  buildVista->setPos(pos);
  return buildVista;
}

Sprite* ViewFactory::getBuildingEffectView(const BuildingEffectType &type,
                                           const std::string &factoryType,
                                           const Position &pos) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  long despX=0, despY=0;
  std::string path = "../src/view/images/buildings/";

  switch (type) {
    case SPIN: {
      type_s = "spin_n";
      num_frames = 8; speed = 20;
      num_frame_return_cycle = 0;
      despX = 9; despY = 1;
      path = path + factoryType + "/" + type_s;
      break;
    }
    case PRODUCT: {
      type_s = "product_n";
      num_frames = 2; speed = 20;
      num_frame_return_cycle = 0;
      despX = 16; despY = 48;
      path = path + factoryType + "/" + type_s;
      break;
    }
    case SMOKE: {
      type_s = "exhaust_n";
      num_frames = 13; speed = 10;
      num_frame_return_cycle = 0;
      despX = 28; despY = -32;
      path = path + type_s;
      break;
    }
    case GREEN_BOX: {
      type_s = "robot/green_box_n";
      num_frames = 6; speed = num_frames;
      num_frame_return_cycle = 0;
      despX = 38; despY = 39;
      path = path + type_s;
      break;
    }
    case VENT: {
      type_s = "vehicle/vent_n";
      num_frames = 4; speed = 20;
      num_frame_return_cycle = 0;
      despX = 16; despY = 33;
      path = path + type_s;
      break;
    }
    case BULB: {
      type_s = "vehicle/bulb_n";
      num_frames = 2; speed = 10;
      num_frame_return_cycle = 0;
      despX = 24; despY = 41;
      path = path + type_s;
      break;
    }

    default: return nullptr;
  }

  Sprite *effectView = new Sprite(path.c_str(), num_frames,
                                  speed, num_frame_return_cycle);
  effectView->setPos(pos.add(despX, despY));
  return effectView;
}

Sprite* ViewFactory::getFlagsVista(const std::string &color,
                                   const Position &pos) {
  int num_frames=4, speed=6, num_frame_return_cycle=0;
  unsigned long despX = 10, despY = 12;

  std::string path = "../src/view/images/flags/flag_" + color + "_n";
  Sprite *flagVista = new Sprite(path.c_str(), num_frames,
                                 speed, num_frame_return_cycle);
  if (color == "grey")
    flagVista->setPos(pos.sub(despX, despY));
  else
    flagVista->setPos(pos);

  return flagVista;
}

Image* ViewFactory::getTerrainObjectVista(const TerrainObjectType &type,
                                          const std::string &state,
                                          const Position &pos) {
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

Sprite* ViewFactory::getBulletVista(const WeaponType &type,
                                    const Position &pos) {
  long despX=0, despY=0;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  std::string path = "../src/view/images/bullet/";
  std::string type_s;

  switch (type) {
    case ROCKET: {
      num_frames=2, speed=2, num_frame_return_cycle=0;
      type_s = "rocket_n";
      break;
    }
    case FIRE: {
      num_frames=4, speed=2, num_frame_return_cycle=0;
      type_s = "fire_n";
      break;
    }
    case BULLET: {
      num_frames=1, speed=1, num_frame_return_cycle=0;
      type_s = "bullet_n";
      break;
    }
    case HCBULLET: {
      num_frames=1, speed=1, num_frame_return_cycle=0;
      type_s = "hcbullet_n";
      break;
    }
    case LASER: {
      num_frames=2, speed=2, num_frame_return_cycle=0;
      type_s = "laser_n";
      break;
    }
    default: return nullptr;
  }

  path = path + type_s;
  Sprite *bulletVista = new Sprite(path.c_str(), num_frames,
                                   speed, num_frame_return_cycle);
  bulletVista->setPos(pos.sub(despX, despY));
  return bulletVista;
}

ExplosionView* ViewFactory::getBulletHitVista(const WeaponType &type,
                                              const Position &pos) {
  switch (type) {
    case ROCKET:
      return new RocketHitView(pos);
      break;
    case HCBULLET:
      return new HCBulletHitView(pos);
      break;
    case FIRE:
      return new FireHitView(pos);
      break;
    case LASER:
      return new LaserHitView(pos);
      break;
    default: return nullptr;
  }
}


Sprite* ViewFactory::getEffectVista(const EffectType &type,
                                    const Position &pos) {
  std::string type_s;
  int num_frames=0, speed=0, num_frame_return_cycle=0;
  long despX=0, despY=0;
  std::string path = "../src/view/images/effects/";

  switch (type) {
    case TANK_MISSILE: {
      type_s = "explosion";
      num_frames = 12; speed = 4;
      num_frame_return_cycle = 0;
      despX = 16; despY = 26;
      path = path + type_s + "/tank_missile_explosion1_n";
      break;
    }
    case SIDE_EXPLOSION: {
      type_s = "explosion";
      num_frames = 7; speed = 3;
      num_frame_return_cycle = 0;
      despX = 16; despY = 16;
      path = path + type_s + "/side_explosion_n";
      break;
    }
    case BIG_SMOKE: {
      type_s = "smoke";
      num_frames = 4; speed = 6;
      num_frame_return_cycle = 0;
      path = path + type_s + "/big_smoke_n";
      break;
    }
    case FIRE_SMOKE: {
      type_s = "smoke";
      num_frames = 4; speed = 6;
      num_frame_return_cycle = 0;
      path = path + type_s + "/small_fire_smoke_n";
      break;
    }
    case FIRE_EFFECT: {
      type_s = "fire";
      num_frames = 6; speed = 6;
      num_frame_return_cycle = 0;
      path = path + type_s + "/fire_n";
      break;
    }
    case FIRE2_EFFECT: {
      type_s = "fire";
      num_frames = 4; speed = 4;
      num_frame_return_cycle = 0;
      path = path + type_s + "/fire2_n";
      break;
    }
    case LASER_EFFECT: {
      type_s = "explosion";
      num_frames = 3; speed = 3;
      num_frame_return_cycle = 0;
      path = path + type_s + "/laser_n";
      break;
    }
    default: return nullptr;
  }

  Sprite *effectView = new Sprite(path.c_str(), num_frames,
                                  speed, num_frame_return_cycle);
  effectView->setPos(pos.sub(despX, despY));
  return effectView;
}
