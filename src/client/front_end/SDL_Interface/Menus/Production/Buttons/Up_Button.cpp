#include "Up_Button.h"
#include <client/front_end/SDL_Interface/Menus/Production/Production_Menu.h>

void Up_Button::button_launch() {
  menu->show_previous_buildable_unit();
}
