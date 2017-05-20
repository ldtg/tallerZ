//
// Created by darius on 19/05/17.
//

#ifndef INTERFAZ_UPPER_BORDER_H
#define INTERFAZ_UPPER_BORDER_H

#include "Border.h"
#include <gtkmm-3.0/gtkmm.h>

class Upper_Border : public Border {
 private:
  Gtk::Fixed * upper_border;

 public:
  Upper_Border(const Glib::RefPtr<Gtk::Builder>& builder);

  virtual gboolean displace_view(GdkEventCrossing * event) override;

 private:
  virtual void load_border_event() override;

  void load_border_masks();
};

#endif //INTERFAZ_UPPER_BORDER_H
