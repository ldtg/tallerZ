//
// Created by darius on 20/05/17.
//

#include <gtest/gtest.h>
#include "../../src/header_for_tests.h"
#include "../../src/front_end/Main_Window.h"

TEST(FrontEndTest,Main_Window){
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(my_argc, my_argv);

  Main_Window interface(my_argc,my_argv);

  app->run(*interface.get_main_window());
}