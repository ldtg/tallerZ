#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <string>
#include <iostream>
#include "front_end/Main_Window.h"

int main( int argc, char **argv )
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv);

    Main_Window interface(argc,argv);

    app->run(*interface.get_main_window());
}

/*
int main( int argc, char* argv[] ) {

    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    return 0;
}
*/

