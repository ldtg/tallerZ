#ifndef TALLERZ_SIDE_BOARD_H
#define TALLERZ_SIDE_BOARD_H

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <client/view/MainWindow.h>
#include <client/view/Texture.h>
#include <client/view/ObjectView.h>
#include <client/front_end/SDL_Interface/Buttons/Quit_Button.h>
#include <client/front_end/SDL_Interface/Buttons/Button.h>
#include <common/Types/UnitType.h>
#include <common/IDs/UnitID.h>

class View;

class Side_Board : public ObjectView {
 private:
  const std::string color;
  const std::string path = "../src/client/front_end/Images/Interface/interface.png";
  const std::string folder_path = "../src/client/front_end/Images/Interface/";

  MainWindow *window;
  Model &model;
  View &view;
  Button *quit_button = NULL;
  bool isUnitSelected = false;
  UnitID unitSelected;

  Texture *face_texture = NULL;
  Texture *weapon_texture = NULL;
  Texture *side_board_texture = NULL;
  Texture *unit_label_background = NULL;
  Texture *unit_label = NULL;
  Texture *weapon_label = NULL;
  Texture *life_bar = NULL;

  const SDL_Rect renderQuad = {0, 0, 800, 600};
  const SDL_Rect face_rect = {706, 46, 86, 72};
  const SDL_Rect weapon_rect = {709, 150, 81, 57};
  const SDL_Rect unit_label_background_rect = {705, 124, 88, 20};
  const SDL_Rect unit_label_rect = {701, 126, 96, 14};
  const SDL_Rect weapon_label_rect = {698, 232, 100, 18};
  const SDL_Rect full_life_bar_rect = {712, 215, 74, 8};
  SDL_Rect life_bar_rect = {712, 215, 74, 8};

 public:
  Side_Board(MainWindow *window, View &view, Model& model, const std::string &color);

  ~Side_Board();

  void scale(float scaleW, float scaleH);

  void load_items();
  bool is_in_quit_button(int x, int y);
  void launch_menu_button();

  void load_unit_images(UnitID unitID);
  void clean_unit_images();

  virtual void set_texture(SDL_Renderer *render) {};
  virtual void draw(SDL_Renderer *render, Camera &camera);


 private:
  std::string label_path(const std::string &name);
  std::string face_path(const std::string &name);
  std::string weapon_path(const std::string &name);
  std::string w_label_path(const std::string &name);
  void set_life_bar_level(unsigned short health){
    life_bar_rect.w = (int)(((double)health/100)*full_life_bar_rect.w);
  }
};

#endif //TALLERZ_SIDE_BOARD_H
