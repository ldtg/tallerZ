//
// Created by darius on 15/06/17.
//

#ifndef TALLERZ_CLIENTLOBBY_H
#define TALLERZ_CLIENTLOBBY_H

#include <gtkmm-3.0/gtkmm.h>
#include <iostream>
#include <Exceptions/lobby_exceptions/Close_Exception.h>

struct Login_Details {
  std::string ip;
  std::string port;
  std::string team;
  std::string map;
};

class clientLobby {
 public:
  Gtk::Window *window;
 private:
  Gtk::Button *connect_button;
  Gtk::Button *cancel_button;
  Gtk::Entry *ip_entry;
  Gtk::Entry *port_entry;
  Gtk::Entry *team_entry;
  Gtk::Entry *map_entry;

  Glib::RefPtr<Gtk::Builder> builder;

  Login_Details login_details;

 public:
  clientLobby();

  ~clientLobby();

  Gtk::Window *get_window() {
    return this->window;
  }
  Login_Details get_login_details() {
    return this->login_details;
  }

  void load_dialog_configurations();

  void load_glade_file(const std::string &file);

  void load_interface_widgets();

  void load_signals();

  void on_cancel_button_activate() {
    this->window->close();
    Gtk::Main::quit();
    throw Close_Exception();
  }

  void on_connect_button_activate() {
    login_details.ip += ip_entry->get_text();
    login_details.port += port_entry->get_text();
    login_details.team += team_entry->get_text();
    login_details.map += map_entry->get_text();
    window->hide();
    window->close();
    Gtk::Main::quit();
  }
};

#endif //TALLERZ_CLIENTLOBBY_H
