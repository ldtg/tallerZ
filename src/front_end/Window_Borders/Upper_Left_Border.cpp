//
// Created by darius on 19/05/17.
//

#include "Upper_Left_Border.h"
Upper_Left_Border::Upper_Left_Border(const Glib::RefPtr<Gtk::Builder>& builder) {
  builder->get_widget("upper_left_corner_border_1",
                      upper_left_corner_border_1);
  builder->get_widget("upper_left_corner_border_2",
                      upper_left_corner_border_2);
  builder->get_widget("upper_left_corner_border_3",
                      upper_left_corner_border_3);
  this->load_border_masks();
  this->load_border_event();
}
gboolean Upper_Left_Border::displace_view(GdkEventCrossing * event) {
  std::cout << "Desplazamiento hacia arriba a la izquierda\n";
  return FALSE;
}
void Upper_Left_Border::load_border_event() {
  upper_left_corner_border_1->signal_enter_notify_event().
      connect(sigc::mem_fun(*this, &Upper_Left_Border::displace_view));
  upper_left_corner_border_2->signal_enter_notify_event().
      connect(sigc::mem_fun(*this, &Upper_Left_Border::displace_view));
  upper_left_corner_border_3->signal_enter_notify_event().
      connect(sigc::mem_fun(*this, &Upper_Left_Border::displace_view));
}
void Upper_Left_Border::load_border_masks() {
  upper_left_corner_border_1->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
  upper_left_corner_border_2->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
  upper_left_corner_border_3->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
}
