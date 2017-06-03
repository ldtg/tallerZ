#include "UnitFactory.h"
Robot UnitFactory::createGrunt(const Position &pos,
                               Player &player,
                               Team &team) {
  return Robot(pos, data.r_grunt, player, team);
}
Robot *UnitFactory::createGruntDynamic(const Position &pos,
                                       Player &player,
                                       Team &team) {
  return new Robot(pos, data.r_grunt, player, team);
}
Vehicle UnitFactory::createJeep(const Position &pos,
                                Player &player,
                                Team &team) {
  return Vehicle(pos, data.v_jeep, data.defaultDriver, player, team);
}
Vehicle *UnitFactory::createJeepDynamic(const Position &pos,
                                        Player &player,
                                        Team &team) {
  return new Vehicle(pos, data.v_jeep, data.defaultDriver, player, team);
}
Robot UnitFactory::createTough(const Position &pos,
                               Player &player,
                               Team &team) {
  return Robot(pos, data.r_tough, player, team);
}
Robot *UnitFactory::createToughDynamic(const Position &pos,
                                       Player &player,
                                       Team &team) {
  return new Robot(pos, data.r_tough, player, team);
}
Unit *UnitFactory::createUnitDynamic(const Position &pos,
                                     const UnitType &type,
                                     Player &player,
                                     Team &team) {
  switch (type) {
    case UnitType::R_GRUNT:return new Robot(pos, data.r_grunt, player, team);
    case UnitType::R_TOUGH:return new Robot(pos, data.r_tough, player, team);
    case UnitType::R_LASER:return new Robot(pos, data.r_laser, player, team);
    case UnitType::R_PYRO:return new Robot(pos, data.r_pyro, player, team);
    case UnitType::R_PSYCHO:return new Robot(pos, data.r_psycho, player, team);
    case UnitType::R_SNIPER:return new Robot(pos, data.r_sniper, player, team);
    case UnitType::V_JEEP:
      return new Vehicle(pos, data.v_jeep, data.defaultDriver, player, team);
    case UnitType::V_LTANK:
      return new Vehicle(pos, data.v_ltank, data.defaultDriver, player, team);
    case UnitType::V_MTANK:
      return new Vehicle(pos, data.v_mtank, data.defaultDriver, player, team);
    case UnitType::V_HTANK:
      return new Vehicle(pos, data.v_htank, data.defaultDriver, player, team);
    case UnitType::V_MML:
      return new Vehicle(pos, data.v_mml, data.defaultDriver, player, team);
  }
}
