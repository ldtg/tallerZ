#include <gtest/gtest.h>
#include <cereal/archives/binary.hpp>
#include <common/DataEvents/Unit/dataUnitMoveEvent.h>
#include <server/model/Events/Unit/serverUMoveEvent.h>
#include <client/model/Events/EventFactory.h>
#include <server/model/Events/Unit/serverUCreateEvent.h>

TEST(serialize_test, position) {
  std::stringstream ss;
  {
    cereal::BinaryOutputArchive oarchive(ss);
    Position pos(1, 1);
    oarchive(pos);
  }
  {
    Position posOut;
    cereal::BinaryInputArchive iarchive(ss);
    iarchive(posOut);
    ASSERT_EQ(Position(1, 1), posOut);
  }

}
TEST(serialize_test, unitID) {
  std::stringstream ss;
  UnitID id(R_GRUNT);
  {
    cereal::BinaryOutputArchive oarchive(ss);
    oarchive(id);
  }
  {
    UnitID idOut(R_GRUNT);
    cereal::BinaryInputArchive iarchive(ss);
    iarchive(idOut);
    ASSERT_EQ(id, idOut);
  }

}
TEST(serialize_test, unitmove) {

}
TEST(serialize_test, srvumoveEvent) {
  //server
  std::stringstream ss;
  serverEvent * se = new serverUMoveEvent(UnitID(R_PSYCHO), Position(10,10));
  ss = se->getDataToSend();
  //cliente primero recibe el type y despues el ss
  Event * ev = EventFactory::createEvent(se->getType(), ss);

}
TEST(serialize_test, srvUCevent) {
  //server
  std::stringstream ss;
  serverEvent * se = new serverUCreateEvent(UnitID(R_PSYCHO),UnitState(R_GRUNT, PlayerID(YELLOW),100,BULLET,Position(100,100)));
  ss = se->getDataToSend();
  //cliente primero recibe el type y despues el ss
  Event * ev = EventFactory::createEvent(se->getType(), ss);

}