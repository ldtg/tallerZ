//
// Created by darius on 19/05/17.
//

#include "Window_Border.h"
Window_Border::Window_Border(const Glib::RefPtr<Gtk::Builder>& builder) {
  left = new Left_Border(builder);
  right = new Right_Border(builder);
  upper = new Upper_Border(builder);
  lower = new Lower_Border(builder);
  upper_left = new Upper_Left_Border(builder);
  upper_right = new Upper_Right_Border(builder);
  lower_left = new Lower_Left_Border(builder);
  lower_right = new Lower_Right_Border(builder);
}

Window_Border::~Window_Border() {
  delete left, right, upper, lower, upper_left, upper_right, lower_left,
      lower_right;
}
