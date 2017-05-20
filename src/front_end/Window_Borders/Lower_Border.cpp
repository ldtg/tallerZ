//
// Created by darius on 19/05/17.
//

#include "Lower_Border.h"
Lower_Border::Lower_Border(const Glib::RefPtr<Gtk::Builder>& builder) {
  builder->get_widget("lower_border", lower_border);
  this->load_border_masks();
  this->load_border_event();
}

gboolean Lower_Border::displace_view(GdkEventCrossing * event) {
  std::cout << "Desplazamiento hacia abajo\n";
  return FALSE;
}

void Lower_Border::load_border_event() {
  lower_border->signal_enter_notify_event().connect(sigc::mem_fun(*this, &Lower_Border::displace_view));
}
void Lower_Border::load_border_masks() {
  lower_border->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
}
