//
// Created by darius on 19/05/17.
//

#ifndef INTERFAZ_RIGHT_BORDER_H
#define INTERFAZ_RIGHT_BORDER_H

#include <iostream>
#include "Border.h"
#include <gtkmm-3.0/gtkmm.h>

class Right_Border : public Border {
 private:
  Gtk::Fixed * right_border;

 public:
  Right_Border(const Glib::RefPtr<Gtk::Builder>& builder);

  virtual gboolean displace_view(GdkEventCrossing * event) override;

 private:
  virtual void load_border_event() override;

  void load_border_masks();
};

#endif //INTERFAZ_RIGHT_BORDER_H
