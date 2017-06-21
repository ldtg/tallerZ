#include "Capturable.h"

Capturable::Capturable(const CapturableType &type) : id(type) {}

CapturableID Capturable::getID() const {
  return id;
}

Capturable::~Capturable() {}
