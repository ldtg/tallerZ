//
// Created by darius on 14/05/17.
//

#ifndef INTERFAZ_INTERFACE_H
#define INTERFAZ_INTERFACE_H

#include <gtkmm-3.0/gtkmm.h>
#include <string>
#include "Robot_Faces/Robot_Face.h"
#include "Timer.h"
#include "Window_Borders/Border.h"
#include "Window_Borders/Window_Border.h"
#include "Figures/Grunt.h"

class Main_Window : public Gtk::Window{
 private:
  Gtk::Window *main_window;
  //Gtk::Button *robot_button;
  Grunt * grunt;
  Glib::RefPtr<Gtk::Builder> builder;

  //panel_lateral
  //Gtk::Image *robot_face_img;
  Gtk::Image *weapon_img;
  Gtk::Label *time_display_lbl;
  Gtk::Label *robot_kind_lbl;
  Gtk::Label *weapon_name_lbl;
  Gtk::Label *robot_units_lbl;
  Gtk::LevelBar *life_bar;
  Gtk::Button *menu_button;
  Gtk::Button *exit_button;

  Window_Border * border;
  Robot_Face * robot_face;
  Timer * time;

 public:
  Main_Window(int argc, char **argv);

  ~Main_Window();

  Gtk::Window * get_main_window(){
    return this->main_window;
  }

 private:
  void load_interface_widgets();

  void load_masks();

  void load_events();

  gboolean entered(GdkEventCrossing * event);
};


#endif //INTERFAZ_INTERFACE_H
