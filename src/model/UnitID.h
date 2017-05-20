#ifndef TALLERZ_IDUNIT_H
#define TALLERZ_IDUNIT_H

#include "UnitType.h"

class UnitID {
  static unsigned long nextid;
 private:
  const UnitType type;
  const unsigned long id;
  UnitType secondType;
 public:
  explicit UnitID(const UnitType &type);
  explicit UnitID(const UnitType &type, const UnitType &second);
  UnitType getUnitType() const;
  UnitType getSecondUnitType() const;
  void setSecondUnitType(const UnitType &type);
  bool operator<(const UnitID &other) const;
  bool operator==(const UnitID &other) const;
  bool operator!=(const UnitID &other) const;
  UnitType getType() const;
};

#endif //TALLERZ_IDUNIT_H
