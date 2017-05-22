#include <gtest/gtest.h>
#include "front_end/SDL_Interface/Main_Window.h"
#include "SDL_START.h"

/*
TEST(FrontEndTest,Main_Window){
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(my_argc, my_argv);

  Main_Window interface(my_argc,my_argv);

  app->run(*interface.get_main_window());
}
*/

TEST(FrontEndTestWithSQL,Main_Window){
  SDL_START();
  Main_Window main_window;

}