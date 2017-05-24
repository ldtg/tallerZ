#include <gtest/gtest.h>
#include "front_end/SDL_Interface/Main_Window.h"
#include "Z_RUNNER.h"
#include "SDL_START.h"
#include "front_end/SDL_Interface/Menus/Production/production_menu_1.h"

TEST(ProductionMenu,production_menu_1){
  SDL_START();
  Window window;
  production_menu_1 menu(window);
  SDL_Delay(3000);
}

TEST(FrontEndTestWithSQL,Z_RUNNER){
  SDL_START();
  Z_RUNNER z_runner;
  z_runner.run();
}