#include <gtest/gtest.h>
#include "front_end/SDL_Interface/Main_Window.h"
#include "Z_RUNNER.h"
#include "SDL_START.h"
#include "front_end/SDL_Interface/Menus/Production/Production_Menu_1.h"

TEST(ProductionMenu,production_menu_1){
  SDL_START start;
  Window window;
  Production_Menu_1 menu(window,15,30);
  SDL_Delay(3000);
  menu.show_building_status();
  SDL_Delay(3000);
  menu.show_select_status();
  SDL_Delay(3000);
  menu.show_health_level(50);
  SDL_Delay(3000);
}

TEST(ProductionMenuDisplacement,production_menu_1){
  SDL_START start;
  Window window;
  Production_Menu_1 menu(window,0,0);
  SDL_Delay(3000);
  menu.displace_toXY(400,400);
  SDL_Delay(3000);
}

TEST(ProductionMenuExpansionWithDisplacement, production_menu_1){
  SDL_START start;
  Window window;
  Production_Menu_1 menu(window, 100, 100);
  SDL_Delay(3000);
  menu.displace_toXY(300,300);
  SDL_Delay(6000);
}
/*
TEST(FrontEndTestWithSQL,Z_RUNNER){
  SDL_START();
  Z_RUNNER z_runner;
  z_runner.run();
}
 */
