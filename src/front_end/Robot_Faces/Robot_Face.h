//
// Created by darius on 14/05/17.
//

#ifndef INTERFAZ_FACE_H
#define INTERFAZ_FACE_H

#include <string>
#include <iostream>
#include <gtkmm-3.0/gtkmm/image.h>
#include <gtkmm-3.0/gtkmm/builder.h>

class Robot_Face {
 private:
  Gtk::Image * robot_face_img;

 public:
  Robot_Face(const Glib::RefPtr<Gtk::Builder>& builder){
    builder->get_widget("robot_face_img", robot_face_img);
  }

  void on_robot_clicked(){
    robot_face_img->set("../src/front_end/Images/Faces/SHEADBI2_0002.png");
  }
};

#endif //INTERFAZ_FACE_H
