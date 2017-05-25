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
  SDL_Rect _time_rect = {87,33,18,10};
  SDL_Rect _unit_rect = {7, 61, 41, 9};
  SDL_Rect _health_rect = {73, 5, 20, 10};
  SDL_Rect _status_rect = {68, 20, 35, 10};
  SDL_Rect _building_name_rect = {5, 5, 65, 11};
  SDL_Rect _expand_b_rect = {96, 5, 10, 10};
  SDL_Rect _cancel_b_rect = {66, 46, 41, 14};
  SDL_Rect _ok_b_rect = {66, 60, 41, 14};

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
  set_absolute_position(_expand_b_rect, this->expand_b_rect);
  this->expand = new Expand_Button(&window, expand_b_rect);

  set_absolute_position(_cancel_b_rect, this->cancel_b_rect);
  this->cancel = new Cancel_Button(&window, cancel_b_rect);

  set_absolute_position(_ok_b_rect, this->ok_b_rect);
  this->ok = new Ok_Button(&window, ok_b_rect);
}
/**
 * displace_toXY
 * @param coorX
 * @param y
 */
void Production_Menu_1::displace_toXY(int x, int y) {
  /*
   *   Texture * background = NULL;
  Label * time = NULL;
  Label *status = NULL;
  Label *health = NULL;
  Label *unit = NULL;
  Label *building_name = NULL;
  Button * ok = NULL;
  Button * expand = NULL;
  Button * cancel = NULL;
   */
  this->renderQuad.x = x;
  this->renderQuad.y = y;
  this->background->renderize(&window, &this->renderQuad);
  this->time->displace_toXY(x,y);
  this->status->displace_toXY(x,y);
  this->health->displace_toXY(x,y);
  this->unit->displace_toXY(x,y);
  this->building_name->displace_toXY(x,y);
  this->ok->displace_toXY(x,y);
  this->expand->displace_toXY(x,y);
  this->cancel->displace_toXY(x,y);
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
 * set_full_position
 * @param rect : rectangulo relativo a la esquina superior izquierda del menu
 * Modifica el parametro ingresado SDL_Rect rect de tal modo que la posicion
 * X e Y es la posición relativa a la ventana.
 * @param rect_abs: rectangulo relativo a la esquina superior izquierda de la
 * pantalla.
 */
void Production_Menu_1::set_absolute_position(SDL_Rect &rect, SDL_Rect& rect_abs) {
  Position _pos = this->get_relative_pos(rect);
  rect_abs.x = _pos.getX();
  rect_abs.y = _pos.getY();
  rect_abs.w = rect.w;
  rect_abs.h = rect.h;
}
/**
 * destructor
 */
Production_Menu_1::~Production_Menu_1() {
  if(this->time != NULL) delete this->time;
  if(this->status != NULL) delete this->status;
  if(this->health != NULL) delete this->health;
  if(this->unit != NULL) delete this->unit;
  if(this->building_name != NULL) delete this->building_name;
  if(this->expand != NULL) delete this->expand;
  if(this->cancel != NULL) delete this->cancel;
  if(this->ok != NULL) delete this->ok;
  if(this->background != NULL) delete this->background;
}
