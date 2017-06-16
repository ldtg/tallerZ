//
// Created by darius on 21/05/17.
//

#include "Side_Board.h"
#include <client/view/View.h>

Side_Board::Side_Board(Window *window, View &view, const std::string &color) :
    window(window), view(view), color(color) {
  this->side_board_texture = new Texture(path, window);
  this->side_board_texture->renderize(window);
  this->load_items();
}

Side_Board::~Side_Board() {
  this->clean_unit_images();
  if (this->menu_button != nullptr) delete this->menu_button;
  if (this->unit_label_background != nullptr)
    delete this->unit_label_background;
  if (this->side_board_texture != nullptr) delete this->side_board_texture;
}

void Side_Board::load_items() {
  this->menu_button = new Quit_Button(window, view);
  std::string unit_label_background_path =
      folder_path + "empty_label_" + color + ".png";
  this->unit_label_background = new Texture(unit_label_background_path, window);

}
bool Side_Board::is_in_menu_button(int x, int y) {
  return menu_button->inRectangle(x, y);
}
void Side_Board::add_to_panel(Panel &panel) {
  panel.add(this);
  panel.add(menu_button);
}
void Side_Board::launch_menu_button() {
  this->menu_button->handle_event();
}
std::string Side_Board::label_path(const std::string &name) {
  return (folder_path + "unit_label_" + name + "_" + color + ".png");
}
std::string Side_Board::face_path(const std::string &name) {
  return (folder_path + "/Faces/" + name + "_" + color + ".png");
}
std::string Side_Board::weapon_path(const std::string &name) {
  return (folder_path + "/Weapons/icon_" + name + "_" + color + ".png");
}
std::string Side_Board::w_label_path(const std::string &name) {
  return (folder_path + "/Weapons/" + name + "_label.bmp");
}

void Side_Board::load_unit_images(UnitType unitType, UnitType secType) {
  this->clean_unit_images();
  switch (unitType) {
    case (R_GRUNT): {
      this->weapon_texture = new Texture(weapon_path("grunt"), window);
      this->weapon_label = new Texture(w_label_path("grunt"), window);
      break;
    }
    case (R_TOUGH): {
      this->weapon_texture = new Texture(weapon_path("tough"), window);
      this->weapon_label = new Texture(w_label_path("tough"), window);
      break;
    }
    case (R_PSYCHO): {
      this->weapon_texture = new Texture(weapon_path("psycho"), window);
      this->weapon_label = new Texture(w_label_path("psycho"), window);
      break;
    }
    case (R_PYRO): {
      this->weapon_texture = new Texture(weapon_path("pyro"), window);
      this->weapon_label = new Texture(w_label_path("pyro"), window);
      break;
    }
    case (R_SNIPER): {
      this->weapon_texture = new Texture(weapon_path("sniper"), window);
      this->weapon_label = new Texture(w_label_path("sniper"), window);
      break;
    }
    case (R_LASER): {
      this->weapon_texture = new Texture(weapon_path("laser"), window);
      this->weapon_label = new Texture(w_label_path("laser"), window);
      break;
    }
    case (V_JEEP): {
      this->weapon_texture = new Texture(weapon_path("jeep"), window);
      this->weapon_label = new Texture(w_label_path("jeep"), window);
      break;
    }
    case (V_MTANK): {
      this->weapon_texture = new Texture(weapon_path("medium"), window);
      this->weapon_label = new Texture(w_label_path("medium"), window);
      break;
    }
    case (V_LTANK): {
      this->weapon_texture = new Texture(weapon_path("light"), window);
      this->weapon_label = new Texture(w_label_path("light"), window);
      break;
    }
    case (V_HTANK): {
      this->weapon_texture = new Texture(weapon_path("heavy"), window);
      this->weapon_label = new Texture(w_label_path("heavy"), window);
      break;
    }
    case (V_MML): {
      this->weapon_texture =
          new Texture(weapon_path("missile_launcher"), window);
      this->weapon_label =
          new Texture(w_label_path("missile_launcher"), window);
      break;
    }
  }
  switch (secType) {
    case (R_GRUNT): {
      this->unit_label = new Texture(label_path("grunt"), window);
      this->face_texture = new Texture(face_path("grunt"), window);
      break;
    }
    case (R_TOUGH): {
      this->unit_label = new Texture(label_path("tough"), window);
      this->face_texture = new Texture(face_path("tough"), window);
      break;
    }
    case (R_PSYCHO): {
      this->unit_label = new Texture(label_path("psycho"), window);
      this->face_texture = new Texture(face_path("psycho"), window);
      break;
    }
    case (R_PYRO): {
      this->unit_label = new Texture(label_path("pyro"), window);
      this->face_texture = new Texture(face_path("pyro"), window);
      break;
    }
    case (R_SNIPER): {
      this->unit_label = new Texture(label_path("sniper"), window);
      this->face_texture = new Texture(face_path("sniper"), window);
      break;
    }
    case (R_LASER): {
      this->unit_label = new Texture(label_path("laser"), window);
      this->face_texture = new Texture(face_path("laser"), window);
      break;
    }
    default: {
      this->unit_label = new Texture(label_path("grunt"), window);
      this->face_texture = new Texture(face_path("grunt"), window);
      break;
    }
  }

  this->unit_label->renderize(window, &unit_label_rect);
  this->weapon_texture->renderize(window, &weapon_rect);
  this->face_texture->renderize(window, &face_rect);
  this->weapon_label->renderize(window, &weapon_label_rect);
}
void Side_Board::clean_unit_images() {
  if (face_texture != nullptr) {
    delete face_texture;
    face_texture = nullptr;
  }
  if (weapon_texture != nullptr) {
    delete weapon_texture;
    weapon_texture = nullptr;
  }
  if (unit_label != nullptr) {
    delete unit_label;
    unit_label = nullptr;
  }
  if (weapon_label != nullptr) {
    delete weapon_label;
    weapon_label = nullptr;
  }
}
