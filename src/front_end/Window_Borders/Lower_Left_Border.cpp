//
// Created by darius on 19/05/17.
//

#include "Lower_Left_Border.h"
Lower_Left_Border::Lower_Left_Border(const Glib::RefPtr<Gtk::Builder>& builder) {
  builder->get_widget("lower_left_corner_border_1",
                      lower_left_corner_border_1);
  builder->get_widget("lower_left_corner_border_2",
                      lower_left_corner_border_2);
  builder->get_widget("lower_left_corner_border_3",
                      lower_left_corner_border_3);
  this->load_border_masks();
  this->load_border_event();
}

gboolean Lower_Left_Border::displace_view(GdkEventCrossing * event) {
  std::cout << "Desplazamiento hacia abajo a la izquierda\n";
  return FALSE;
}
void Lower_Left_Border::load_border_event() {
  lower_left_corner_border_1->signal_enter_notify_event().
      connect(sigc::mem_fun(*this, &Lower_Left_Border::displace_view));
  lower_left_corner_border_2->signal_enter_notify_event().
      connect(sigc::mem_fun(*this, &Lower_Left_Border::displace_view));
  lower_left_corner_border_3->signal_enter_notify_event().
      connect(sigc::mem_fun(*this, &Lower_Left_Border::displace_view));
}
void Lower_Left_Border::load_border_masks() {
  lower_left_corner_border_1->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
  lower_left_corner_border_2->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
  lower_left_corner_border_3->set_events(Gdk::POINTER_MOTION_MASK | Gdk::ENTER_NOTIFY_MASK );
}
