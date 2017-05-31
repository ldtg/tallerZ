#include "UnitFactory.h"
Robot UnitFactory::createGrunt(const Position &pos,
                               Player &player,
                               Team &team) {
  return Robot(pos, data.grunt, player, team);
}
Robot *UnitFactory::createGruntDynamic(const Position &pos,
                                       Player &player,
                                       Team &team) {
  return new Robot(pos, data.grunt, player, team);
}
Vehicle UnitFactory::createJeep(const Position &pos,
                                Player &player,
                                Team &team) {
  return Vehicle(pos, data.jeep, data.defaultDriver, player, team);
}
Vehicle *UnitFactory::createJeepDynamic(const Position &pos,
                                        Player &player,
                                        Team &team) {
  return new Vehicle(pos, data.jeep, data.defaultDriver, player, team);
}
Robot UnitFactory::createTough(const Position &pos,
                               Player &player,
                               Team &team) {
  return Robot(pos, data.tough, player, team);
}
Robot *UnitFactory::createToughDynamic(const Position &pos,
                                       Player &player,
                                       Team &team) {
  return new Robot(pos, data.tough, player, team);
}
Unit *UnitFactory::createUnitDynamic(const Position &pos,
                                     const UnitType &type,
                                     Player &player,
                                     Team &team) {
  switch (type) {
    case UnitType::R_GRUNT:return new Robot(pos, data.grunt, player, team);
    case UnitType::R_TOUGH:return new Robot(pos, data.tough, player, team);
    case UnitType::V_JEEP:
      return new Vehicle(pos,
                         data.jeep,
                         data.defaultDriver, player, team);
  }
}
