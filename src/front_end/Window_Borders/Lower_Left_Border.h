//
// Created by darius on 19/05/17.
//

#ifndef INTERFAZ_LOWER_LEFT_BORDER_H
#define INTERFAZ_LOWER_LEFT_BORDER_H

#include <gtkmm-3.0/gtkmm.h>
#include "Border.h"
class Lower_Left_Border : public Border {
 private:
  Gtk::Fixed * lower_left_corner_border_1;
  Gtk::Fixed * lower_left_corner_border_2;
  Gtk::Fixed * lower_left_corner_border_3;

 public:
  Lower_Left_Border(const Glib::RefPtr<Gtk::Builder>& builder);

  virtual gboolean displace_view(GdkEventCrossing * event) override;

 private:
  virtual void load_border_event() override;

  void load_border_masks();
};

#endif //INTERFAZ_LOWER_LEFT_BORDER_H
