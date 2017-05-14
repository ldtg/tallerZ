#ifndef TALLERZ_IDUNIT_H
#define TALLERZ_IDUNIT_H
#include "UnitType.h"
class UnitID {
  static unsigned long nextid;
 private:
  UnitType type;
  unsigned long id;
 public:
  UnitID(UnitType type);
  bool operator<(const UnitID &other) const;
};

#endif //TALLERZ_IDUNIT_H
