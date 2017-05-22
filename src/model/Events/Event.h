#ifndef TALLERZ_EVENT_H
#define TALLERZ_EVENT_H

class View;
class Model;

#include <view/View.h>
#include <model/Model.h>

class Event {
 protected:
  Model &model;
  View &view;
 public:
  Event(Model &model,View &view);
  void setModel(Model &model);
  void setView(View &view);
  virtual void process() = 0;
};

#endif //TALLERZ_EVENT_H
