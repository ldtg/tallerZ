//
// Created by darius on 23/05/17.
//

#include <front_end/SDL_Interface/Menus/Production/Buttons/Expand_Button.h>
#include <front_end/SDL_Interface/Menus/Production/Buttons/Cancel_Button.h>
#include <front_end/SDL_Interface/Menus/Production/Buttons/Ok_Button.h>
#include "Production_Menu_1.h"
/**
 * constructor
 * @param window : ventana sobre la que se renderiza
 * @param x : coordenada X del menu
 * @param y : coordenada Y del menu
 */
Production_Menu_1::Production_Menu_1(Window &window, int x, int y) : window(window) {
  this->renderQuad = { x, y, width, length};
  this->background = new Texture(background_path.c_str(), &window);
  this->background->renderize(&window, &renderQuad);
  load_items();
}
/**
 * load_items
 */
void Production_Menu_1::load_items() {
  /******Labels*****/
  set_absolute_position(_time_rect, this->time_rect);
  this->time = new Label(window, "01:00", this->time_rect);

  set_absolute_position(_unit_rect, this->unit_rect);
  this->unit = new Label(window, "Robot", this->unit_rect);

  set_absolute_position(_health_rect, this->health_rect);
  this->health = new Label(window, "100%", this->health_rect);

  set_absolute_position(_building_name_rect, this->building_name_rect);
  this->building_name = new Label(window, "Factory", this->building_name_rect);

  set_absolute_position(_status_rect, this->status_rect);
  this->status = new Label(window, "Select", this->status_rect);

  /******Buttons*****/
  set_absolute_position(_cancel_b_rect, this->cancel_b_rect);
  this->cancel = new Cancel_Button(&window, cancel_b_rect);

  set_absolute_position(_ok_b_rect, this->ok_b_rect);
  this->ok = new Ok_Button(&window, ok_b_rect);

  set_absolute_position(_up_rect, this->up_rect);
  this->up = new Up_Button(&window, up_rect);

  set_absolute_position(_down_rect, this->down_rect);
  this->down = new Down_Button(&window, down_rect);
}
/**
 * displace_toXY : mueve el menu a las coordenadas x,y
 * @param x : coordenada x
 * @param y : coordenada y
 */
void Production_Menu_1::displace_toXY(int x, int y) {
  this->renderQuad.x = x;
  this->renderQuad.y = y;
  this->background->renderize(&window, &this->renderQuad);

  if(this->joint_menu != NULL){
    joint_menu->displace_toXY(renderQuad.x + renderQuad.w, renderQuad.y);
  }

  this->set_absolute_position(_time_rect, time_rect);
  this->time->set_rectangle(time_rect);
  this->time->reload();

  this->set_absolute_position(_status_rect, status_rect);
  this->status->set_rectangle(status_rect);
  this->status->reload();

  this->set_absolute_position(_health_rect, health_rect);
  this->health->set_rectangle(health_rect);
  this->health->reload();

  this->set_absolute_position(_unit_rect, unit_rect);
  this->unit->set_rectangle(unit_rect);
  this->unit->reload();

  this->set_absolute_position(_building_name_rect, building_name_rect);
  this->building_name->set_rectangle(building_name_rect);
  this->building_name->reload();

  this->set_absolute_position(_ok_b_rect, ok_b_rect);
  this->ok->set_rectangle(ok_b_rect);
  this->ok->reload();

  this->set_absolute_position(_cancel_b_rect, cancel_b_rect);
  this->cancel->set_rectangle(cancel_b_rect);
  this->cancel->reload();

  this->set_absolute_position(_up_rect, up_rect);
  this->up->set_rectangle(up_rect);
  this->up->reload();

  this->set_absolute_position(_down_rect, down_rect);
  this->down->set_rectangle(down_rect);
  this->down->reload();
}
/**
 * show_select_status: En lugar de Building pone Select
 */
void Production_Menu_1::show_select_status() {
  this->status->modify_text("Select");
}
/**
 * show_building_status: En lugar de Select pone Building
 */
void Production_Menu_1::show_building_status() {
  this->status->modify_text("Building");
}
/**
 * show_health_level
 * @param health : nivel de salud de la fabrica.
 */
void Production_Menu_1::show_health_level(int health) {
  this->health->modify_text(std::to_string(health)+"%");
}
/**
 * destructor
 */
Production_Menu_1::~Production_Menu_1() {
  if(this->joint_menu != NULL) delete this->joint_menu;
  if(this->time != NULL) delete this->time;
  if(this->status != NULL) delete this->status;
  if(this->health != NULL) delete this->health;
  if(this->unit != NULL) delete this->unit;
  if(this->building_name != NULL) delete this->building_name;
  if(this->cancel != NULL) delete this->cancel;
  if(this->ok != NULL) delete this->ok;
  if(this->up != NULL) delete this->up;
  if(this->down != NULL) delete this->down;
  if(this->background != NULL) delete this->background;
}

