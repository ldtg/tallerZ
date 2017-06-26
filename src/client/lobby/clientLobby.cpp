//
// Created by darius on 15/06/17.
//

#include "clientLobby.h"
void clientLobby::load_glade_file(const std::string &file) {
  try {
    this->builder = Gtk::Builder::create_from_file(file);
  } catch (const Glib::FileError &e) {
    std::cout << e.what();
  }
}
void clientLobby::load_interface_widgets() {
  builder->get_widget("window", window);
  builder->get_widget("connect_button", connect_button);
  builder->get_widget("cancel_button", cancel_button);
  builder->get_widget("ip_entry", ip_entry);
  builder->get_widget("port_entry", port_entry);
  builder->get_widget("team_entry", team_entry);
  builder->get_widget("map_entry", map_entry);
}

void clientLobby::load_signals() {
  this->connect_button->signal_clicked().connect(sigc::mem_fun(*this, &clientLobby::on_connect_button_activate));
  this->cancel_button->signal_clicked().connect(sigc::mem_fun(*this, &clientLobby::on_cancel_button_activate));
}

void clientLobby::load_dialog_configurations() {
  this->window->set_position(Gtk::WIN_POS_CENTER);
}

clientLobby::clientLobby() {
  load_glade_file("../src/client/front_end/Login_Menu2.glade");
  load_interface_widgets();
  load_dialog_configurations();
  load_signals();
}
