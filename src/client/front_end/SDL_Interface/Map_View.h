//
// Created by darius on 22/05/17.
//

#ifndef TALLERZ_GAME_VIEW_H
#define TALLERZ_GAME_VIEW_H

#include <SDL_rect.h>
class Map_View {
 private:
  const SDL_Rect map_rect = {0, 0, 547, 448};

 public:
  bool inMapRect(int x, int y);

  SDL_Rect get_map_rect() const;
};

#endif //TALLERZ_GAME_VIEW_H
