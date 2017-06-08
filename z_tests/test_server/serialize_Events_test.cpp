#include <gtest/gtest.h>
#include <cereal/archives/binary.hpp>
#include <common/DataEvents/dataUnitMoveEvent.h>

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
  dataUnitMoveEvent umOut(UnitID(R_SNIPER), Position(1,1));
  ss = umOut.getStream();
  dataUnitMoveEvent umIn(ss);
  ASSERT_EQ(umIn.posTo, umOut.posTo);
  ASSERT_EQ(umIn.id, umOut.id);
}