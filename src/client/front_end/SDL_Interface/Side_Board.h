//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_SIDE_BOARD_H
#define TALLERZ_SIDE_BOARD_H

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <client/view/Window.h>
#include <client/view/Texture.h>
#include <client/view/ObjectMapaVista.h>
#include <client/view/Panel.h>
#include <client/front_end/SDL_Interface/Buttons/Quit_Button.h>
#include <client/front_end/SDL_Interface/Buttons/Button.h>
#include <common/Types/UnitType.h>
class View;
class Side_Board : public ObjectMapaVista{
 private:
  const std::string color;
  const std::string path = "../src/client/front_end/Images/Interface/interface.png";
  const std::string folder_path = "../src/client/front_end/Images/Interface/";

  Window * window;
  View& view;
  Button * menu_button = NULL;

  Texture * face_texture = NULL;
  Texture * weapon_texture = NULL;
  Texture * side_board_texture = NULL;
  Texture * unit_label_background = NULL;
  Texture * unit_label = NULL;
  Texture * weapon_label = NULL;

  const SDL_Rect renderQuad = {0,0,800, 600};
  const SDL_Rect face_rect = {707,45,86,72};
  const SDL_Rect weapon_rect = {710, 149, 81, 57};
  const SDL_Rect unit_label_background_rect = {706, 123, 88, 20};
  const SDL_Rect unit_label_rect = {702, 125, 96, 14};
  const SDL_Rect weapon_label_rect = {699, 231, 100, 18};

 public:
  Side_Board(Window * window, View& view, const std::string& color);

  ~Side_Board();

  void load_items();
  bool is_in_menu_button(int x, int y);
  void launch_menu_button();

  void load_unit_images(const UnitType& unitType );
  void clean_unit_images();
  void add_to_panel(Panel& panel);

  virtual void set_texture(SDL_Renderer *render){};
  virtual void draw(SDL_Renderer *render, Camera &camera){
    SDL_RenderCopy(render, side_board_texture->get_texture(), NULL, NULL);
    unit_label_background->renderize(window, &unit_label_background_rect);
    if (this->face_texture != NULL){
      this->face_texture->renderize(window, &face_rect);
    }
    if (this->weapon_texture != NULL){
      this->weapon_texture->renderize(window, &weapon_rect);
    }
    if (this->unit_label != NULL){
      this->unit_label->renderize(window, &unit_label_rect);
    }
    if (this->weapon_label != NULL){
      this->weapon_label->renderize(window, &weapon_label_rect);
    }
  }

 private:
  std::string label_path(const std::string& name);
  std::string face_path(const std::string& name);
  std::string weapon_path(const std::string& name);
  std::string w_label_path(const std::string& name);

};

#endif //TALLERZ_SIDE_BOARD_H
