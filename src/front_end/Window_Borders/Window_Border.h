//
// Created by darius on 19/05/17.
//

#ifndef INTERFAZ_WINDOW_BORDER_H
#define INTERFAZ_WINDOW_BORDER_H

#include "Border.h"
#include "Lower_Right_Border.h"
#include "Lower_Left_Border.h"
#include "Lower_Border.h"
#include "Left_Border.h"
#include "Right_Border.h"
#include "Upper_Right_Border.h"
#include "Upper_Left_Border.h"
#include "Upper_Border.h"
#include <gtkmm-3.0/gtkmm.h>

class Window_Border {
 private:
  /*Border * left;
  Border * right;
  Border * upper;
  Border * lower;
  Border * upper_left;
  Border * upper_right;
  Border * lower_left;
  Border * lower_right;*/

  Left_Border * left;
  Right_Border * right;
  Upper_Border * upper;
  Lower_Border * lower;
  Border * upper_left;
  Border * upper_right;
  Border * lower_left;
  Border * lower_right;

 public:
  Window_Border(const Glib::RefPtr<Gtk::Builder>& builder);

  ~Window_Border();
};

#endif //INTERFAZ_WINDOW_BORDER_H
