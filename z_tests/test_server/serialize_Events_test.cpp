#include <gtest/gtest.h>
#include <server/model/Events/UnitMoveEvent.h>
#include <cereal/archives/binary.hpp>
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
  std::stringstream ss;
  cereal::BinaryOutputArchive oarchive(ss);
  UnitMoveEvent evOut(UnitID(UnitType::R_SNIPER), Position(1, 1));
  oarchive(evOut);
  UnitMoveEvent evIn;
  cereal::BinaryInputArchive iarchive(ss);
  iarchive(evIn);
  ASSERT_EQ(Position(1, 1), evIn.posTo);
  ASSERT_EQ(UnitType::R_SNIPER, evIn.id.getType());

}