//
// Created by darius on 23/05/17.
//

#ifndef TALLERZ_PRODUCTION_MENU_1_H
#define TALLERZ_PRODUCTION_MENU_1_H

#include <string>
#include <SDL2/SDL_ttf.h>
#include "common/Map/Position.h"
#include <client/front_end/SDL_Interface/Buttons/Button.h>
#include <client/front_end/SDL_Interface/Menus/Menu.h>
#include <client/front_end/SDL_Interface/Labels/Label.h>
#include <client/front_end/SDL_Interface/Menus/Production/Buttons/Cancel_Button.h>
#include <client/front_end/SDL_Interface/Menus/Production/Buttons/Ok_Button.h>
#include <client/front_end/SDL_Interface/Menus/Production/Buttons/Up_Button.h>
#include <client/front_end/SDL_Interface/Menus/Production/Buttons/Down_Button.h>
#include <common/IDs/BuildID.h>
#include <common/Types/UnitType.h>
#include <common/States/BuildState.h>

class Model;

class Production_Menu : public Menu {
 private:
  const int width = 111;
  const int length = 79;
  Window &window;
  Model &model;
  const BuildID buildID;
  const BuildState& buildState;
  UnitType showing_unit_type;

  Label * time = NULL;
  Label *status = NULL;
  Label *health = NULL;
  Label *unit = NULL;
  Label *building_name = NULL;
  Button * ok = NULL;
  Button * cancel = NULL;
  Button * up = NULL;
  Button * down = NULL;

  SDL_Rect time_rect;
  SDL_Rect unit_rect;
  SDL_Rect health_rect;
  SDL_Rect status_rect;
  SDL_Rect building_name_rect;
  SDL_Rect cancel_b_rect;
  SDL_Rect ok_b_rect;
  SDL_Rect up_rect;
  SDL_Rect down_rect;

  SDL_Rect _time_rect = {87,33,18,10};
  SDL_Rect _unit_rect = {7, 61, 41, 9};
  SDL_Rect _health_rect = {73, 5, 20, 10};
  SDL_Rect _status_rect = {68, 20, 35, 10};
  SDL_Rect _building_name_rect = {5, 5, 65, 11};
  SDL_Rect _cancel_b_rect = {66, 46, 41, 14};
  SDL_Rect _ok_b_rect = {66, 60, 41, 14};
  SDL_Rect _up_rect = {50, 21, 13, 13};
  SDL_Rect _down_rect = {50, 62, 13, 13};

  const std::string background_path
      = "../src/client/front_end/Images/Interface/production_gui/base_image.png";

 public:
  Production_Menu(const BuildID buildID,
                  const BuildState &buildState,
                  Window &window,
                  Model& model,
                  int x, int y);

  void displace_toXY(int x, int y);

  void show_health_level(int health);

  void show_select_status();

  void show_building_status();

  void show_previous_buildable_unit();

  void show_next_buildable_unit();

  void add_to_panel(Panel& panel);

  void update_unit_to_build();

  void handle_click(int x, int y);

  ~Production_Menu();

 private:
  void load_items();

  std::string get_building_type(const BuildType& buildType);

  std::string get_unit_name(const UnitType& utype);
};

#endif //TALLERZ_PRODUCTION_MENU_1_H
