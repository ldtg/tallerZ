#include "BulletID.h"
unsigned long BulletID::nextid = 0;
BulletID::BulletID() : id(nextid) {
  nextid++;
}
bool BulletID::operator<(const BulletID &other) const {
  return this->id < other.id;
}
