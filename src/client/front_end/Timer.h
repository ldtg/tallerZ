//
// Created by darius on 14/05/17.
//

#ifndef TIMER_H
#define TIMER_H

#include <gtkmm-3.0/gtkmm/label.h>
#include <unistd.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

class Timer{
 private:
  unsigned int seconds;
  unsigned int minutes;
  unsigned int hours;
  std::string moment;
  Gtk::Label *timer_lbl;
  bool pause = false;

 public:
  Timer(Gtk::Label * timer);

  ~Timer(){}

  void pause_timer();

  void run();

 private:
  void inc_hour();

  void inc_minute();

  void inc_by_a_second();

  void update_moment();
};

#endif //TIMER_H
