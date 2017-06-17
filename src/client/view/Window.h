#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <vector>
#include <client/front_end/SDL_Interface/Cursor.h>

#define WINDOWWIDHT 800
#define WINDOWHEIGHT 600

class Window {
 private:
  SDL_Window *window;
  SDL_Renderer *window_render;

  Cursor *cursor;

  int width;
  int height;

 public:
  Window();
  ~Window();
  SDL_Renderer *getRender() const;
  SDL_Window *getWindow() const;
  int getWidth() const;
  int getHeight() const;
  void update();
};

#endif //WINDOW_H
