//
// Created by darius on 19/05/17.
//

#include "Upper_Right_Border.h"
Upper_Right_Border::Upper_Right_Border(const Glib::RefPtr<Gtk::Builder>& builder) {
  builder->get_widget("upper_right_corner_border_1",
                      upper_right_corner_border_1);
  builder->get_widget("upper_right_corner_border_2",
                      upper_right_corner_border_2);
  builder->get_widget("upper_right_corner_border_3",
                      upper_right_corner_border_3);
  this->load_border_masks();
  this->load_border_event();
}

gboolean Upper_Right_Border::displace_view(GdkEventCrossing * event) {
  std::cout << "Desplazamiento hacia arriba a la derecha\n";
  return FALSE;
}
void Upper_Right_Border::load_border_event() {
  upper_right_corner_border_1->signal_enter_notify_event().
      connect(sigc::mem_fun(*this, &Upper_Right_Border::displace_view));
  upper_right_corner_border_2->signal_enter_notify_event().
      connect(sigc::mem_fun(*this, &Upper_Right_Border::displace_view));
  upper_right_corner_border_3->signal_enter_notify_event().
      connect(sigc::mem_fun(*this, &Upper_Right_Border::displace_view));
}
void Upper_Right_Border::load_border_masks() {
  upper_right_corner_border_1->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
  upper_right_corner_border_2->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
  upper_right_corner_border_3->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
}
