//
// Created by darius on 19/05/17.
//

#ifndef INTERFAZ_BORDE_H
#define INTERFAZ_BORDE_H

#include <iostream>
#include <gtkmm-3.0/gtkmm.h>
class Border {
 public:
  Border(){}

  virtual gboolean displace_view(GdkEventCrossing * event){ std::cout << "xxxx\n";}

 protected:
  /*
   * load_border_events
   * Se cargan los eventos de detección del puntero que van a permitir
   * la vista de aguila: cuando el puntero se ubique en uno de los bordes
   * se notificará de ello al programa.
   */
  virtual void load_border_event() = 0;
};

#endif //INTERFAZ_BORDE_H
