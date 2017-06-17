#ifndef TALLERZ_EVENT_H
#define TALLERZ_EVENT_H

class View;
class Model;

#include <client/view/View.h>
#include <client/model/Model.h>

class Event {
 protected:
  Model *model;
  View *view;
 public:
//  Event();
  void setModel(Model *model);
  void setView(View *view);
  virtual void process() = 0;
  virtual ~Event() {};
};

#endif //TALLERZ_EVENT_H
