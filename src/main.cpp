#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>
#include <iostream>

//Variables globales para los tests de front end
//(hace falta para usar Gtk::Application). DU not tuch
int my_argc;
char **my_argv;

int main(int argc, char *argv[]) {
  int warning;
  testing::InitGoogleTest(&argc, argv);
  my_argc = argc;
  my_argv = argv;

  warning = RUN_ALL_TESTS();

  return 0;
}


