//
// Created by darius on 21/05/17.
//

#ifndef TALLERZ_WEAPON_IMG_H
#define TALLERZ_WEAPON_IMG_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

enum weapon_icons{
  GRUNT_BLUE, GRUNT_GREEN, GRUNT_RED, GRUNT_YELLOW, MAX_WEAPONS
};

const std::string weapon_files[MAX_WEAPONS]{
  "icon_grunt_blue.png",
  "icon_grunt_green.png",
  "icon_grunt_red.png",
  "icon_grunt_yellow.png"
};

const std::string weapon_image_path = "../src/front_end/Images/Weapons/";

class Weapon_Img {
 private:
  SDL_Surface * weapon_img;
 public:

};

#endif //TALLERZ_WEAPON_IMG_H
