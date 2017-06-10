//
// Created by darius on 24/05/17.
//

#include "Ok_Button.h"
#include <client/front_end/SDL_Interface/Menus/Production/Production_Menu.h>

void Ok_Button::button_launch() {
  this->menu->update_unit_to_build();
}
