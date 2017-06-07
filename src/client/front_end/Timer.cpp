//
// Created by darius on 14/05/17.
//

#include <chrono>
#include <thread>
#include "Timer.h"

//update_moment
//Se encarga de actualizar el string del label "timer".
void Timer::update_moment() {
  std::stringstream buffer;
  buffer << std::setfill('0') << std::setw(2) << hours << ":"
         << std::setfill('0') << std::setw(2) << minutes << ":"
         << std::setfill('0') << std::setw(2) << seconds;

  this->moment = buffer.str();
}

//inc_by_a_second
//Incrementa por un segundo el tiempo indicado en timer.
void Timer::inc_by_a_second() {
  this->seconds++;
  if (this->seconds >= 60) {
    this->seconds = 0;
    inc_minute();
  }
}

//inc_minute
//Metodo privado: se incrementa en uno los minutos.
//Invocado cuando se superan los 60 segundos.
void Timer::inc_minute() {
  this->minutes++;
  if (this->minutes >= 60) {
    this->minutes = 0;
    inc_hour();
  }
}

//inc_hour
//Metodo privado: se incrementa en uno las horas.
//Invocado cuando se superan los 60 minutos.
void Timer::inc_hour() {
  this->hours++;
}

//run
//Setea el texto (tiempo) del label Timer de la interfaz a cada segundo.
//Mientras no se pause desde otro thread no se detiene.
void Timer::run() {

  std::chrono::seconds pause_interval(1);
  int i;
  for (i = 0; i < 1; i++){
    inc_by_a_second();
    update_moment();
    this->timer_lbl->set_text(this->moment);
    std::this_thread::sleep_for(pause_interval);
  }
}

void Timer::pause_timer() {
  this->pause = true;
}

//constructor
Timer::Timer(Gtk::Label *timer) {
  this->seconds = 0;
  this->minutes = 0;
  this->hours = 0;
  this->moment = "00:00:00";
  this->timer_lbl = timer;

  timer_lbl->set_text(this->moment);
}
