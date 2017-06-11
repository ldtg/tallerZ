#include <SDL_START.h>
#include <client/view/Window.h>
#include <client/view/Panel.h>
#include "gtest/gtest.h"

TEST(window_create, Window) {
  SDL_START();
  Window window;
  SDL_Delay(7000);
}

TEST(panel_create, Panel) {
  SDL_START();
  Window window;
  Panel panel(window.getRender());
  SDL_Delay(7000);
}
