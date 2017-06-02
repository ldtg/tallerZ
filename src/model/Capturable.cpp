#include "Capturable.h"
CapturableID Capturable::getID() const {
  return id;
}
Capturable::Capturable(const CapturableType &type) : id(type) {}
