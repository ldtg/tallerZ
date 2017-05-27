#include "UnitFactory.h"
Robot UnitFactory::createGrunt(const Position &pos) {
  return Robot(pos, data.grunt);
}
Robot *UnitFactory::createGruntDynamic(const Position &pos) {
  return new Robot(pos, data.grunt);
}
Vehicle UnitFactory::createJeep(const Position &pos) {
  return Vehicle(pos, data.jeep, data.defaultDriver);
}
Vehicle *UnitFactory::createJeepDynamic(const Position &pos) {
  return new Vehicle(pos, data.jeep, data.defaultDriver);
}
Robot UnitFactory::createTough(const Position &pos) {
  return Robot(pos, data.tough);
}
Robot *UnitFactory::createToughDynamic(const Position &pos) {
  return new Robot(pos, data.tough);
}
