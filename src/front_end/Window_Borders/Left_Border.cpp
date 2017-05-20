//
// Created by darius on 19/05/17.
//

#include "Left_Border.h"
Left_Border::Left_Border(const Glib::RefPtr<Gtk::Builder>& builder) {
  builder->get_widget("left_border", left_border);
  this->load_border_masks();
  this->load_border_event();
}

gboolean Left_Border::displace_view(GdkEventCrossing * event) {
  std::cout << "Desplazamiento hacia la izquierda\n";
  return FALSE;
}
void Left_Border::load_border_event() {
  left_border->signal_enter_notify_event().connect(sigc::mem_fun(*this, &Left_Border::displace_view));
}
void Left_Border::load_border_masks() {
  left_border->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
}
