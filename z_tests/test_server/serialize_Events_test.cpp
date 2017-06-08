#include <gtest/gtest.h>
#include <cereal/archives/binary.hpp>
#include <common/DataEvents/dataUnitMoveEvent.h>
#include <server/model/Events/serverUMoveEvent.h>
#include <client/model/Events/EventFactory.h>

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