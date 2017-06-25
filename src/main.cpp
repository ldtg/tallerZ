
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int maain(int argc, char *argv[]) {
  int warning;
  testing::InitGoogleTest(&argc, argv);
  warning = RUN_ALL_TESTS();

  warning = RUN_ALL_TESTS();
  return 0;
}


