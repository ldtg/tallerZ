//
// Created by darius on 19/05/17.
//

#include "Right_Border.h"
Right_Border::Right_Border(const Glib::RefPtr<Gtk::Builder>& builder) {
  builder->get_widget("right_border", right_border);
  this->load_border_masks();
  this->load_border_event();
}
gboolean Right_Border::displace_view(GdkEventCrossing * event) {
  std::cout << "Desplazamiento hacia la derecha\n";
  return FALSE;
}
void Right_Border::load_border_masks() {
  right_border->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
}
void Right_Border::load_border_event() {
  right_border->signal_enter_notify_event().connect(sigc::mem_fun(*this, &Right_Border::displace_view));
}
