//
// Created by darius on 19/05/17.
//

#include "Upper_Border.h"
Upper_Border::Upper_Border(const Glib::RefPtr<Gtk::Builder>& builder) {
  builder->get_widget("upper_border", upper_border);
  this->load_border_masks();
  this->load_border_event();
}
gboolean Upper_Border::displace_view(GdkEventCrossing * event) {
  std::cout << "Desplazamiento hacia arriba\n";
  return FALSE;
}
void Upper_Border::load_border_event() {
  upper_border->signal_enter_notify_event().connect(sigc::mem_fun(*this, &Upper_Border::displace_view));
}
void Upper_Border::load_border_masks() {
  upper_border->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
}
