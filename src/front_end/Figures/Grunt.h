//
// Created by darius on 20/05/17.
//

#ifndef INTERFAZ2_GRUNT_H
#define INTERFAZ2_GRUNT_H

#include <gtkmm-3.0/gtkmm/builder.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include "../Robot_Faces/Robot_Face.h"

class Grunt {
 private:
  Gtk::Button * grunt;
  Robot_Face& robot_face;
 public:
  Grunt(const Glib::RefPtr<Gtk::Builder>& builder, Robot_Face& robot_face) :
      robot_face(robot_face){
    builder->get_widget("robotito", grunt);
    load_events();
  }

  void load_events(){
    grunt->signal_clicked().connect(
        sigc::mem_fun(this->robot_face, &Robot_Face::on_robot_clicked));
  }
};

#endif //INTERFAZ2_GRUNT_H
