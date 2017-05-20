//
// Created by darius on 19/05/17.
//
#include "Main_Window.h"

/*
 * EN PLENO DESARROLLO
 */


Main_Window::Main_Window(int argc, char **argv) {
  std::string glade_file = "../src/front_end/Interface.glade";
  builder = Gtk::Builder::create_from_file(glade_file);

  this->load_interface_widgets();
  this->border = new Window_Border(builder);
  this->robot_face = new Robot_Face(builder);
  this->grunt = new Grunt(builder, *this->robot_face);

  //this->load_masks();
  //robot_button->signal_clicked().connect(sigc::mem_fun(this->robot_face, &Robot_Face::on_robot_clicked));
  //main_window->signal_enter_notify_event().connect(sigc::mem_fun(*this, &Main_Window::entered));

  //window_settings
  //main_window->fullscreen();


  //this->time = new Timer(time_display_lbl);
}

//load_masks
//Las mascaras nos permiten detectar eventos como cuando el puntero
//se posicionó sobre una ventana. Load masks carga las mascaras necesarias.
void Main_Window::load_masks() {
  main_window->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
}

Main_Window::~Main_Window() {
  delete this->border;
  delete this->robot_face;
  delete this->grunt;
}

void Main_Window::load_interface_widgets() {

    //elementos para pruebas:
    //builder->get_widget("robotito", robot_button);
    //fin elementos para pruebas.

  //Panel Lateral
  builder->get_widget("main_window",main_window);
  //builder->get_widget("robot_face_img", robot_face_img);
  builder->get_widget("weapon_img",weapon_img);
  builder->get_widget("time_display_lbl", time_display_lbl);
  builder->get_widget("robot_kind_lbl", robot_kind_lbl);
  builder->get_widget("weapon_name_lbl", weapon_name_lbl);
  builder->get_widget("robot_units_lbl", robot_units_lbl);
  builder->get_widget("life_bar", life_bar);
  builder->get_widget("menu_button", menu_button);
  builder->get_widget("exit_button", exit_button);

}

/*************EVENTOS************/
///entered
///Evento que se ejecuta al pasar el cursor sobre la ventana de juego.
///TODO: mejorar
gboolean Main_Window::entered(GdkEventCrossing *event) {
  Gdk::Display * display;
  std::cout << "lalala\n";
  /*if (event->type == GDK_ENTER_NOTIFY) {
    auto window = main_window->get_window();
    Gdk::Cursor *cursor;
    auto pointer =
        display->get_default()->get_device_manager()->get_client_pointer();
    pointer->grab(this->main_window->get_window(),
                  Gdk::OWNERSHIP_WINDOW,
                  TRUE,
                  Gdk::POINTER_MOTION_MASK,
                  cursor->create(Gdk::CROSSHAIR),
                  event->time);
  }*/
  return FALSE;
}

void Main_Window::load_events() {

}

