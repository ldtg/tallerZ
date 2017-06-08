#ifndef TALLERZ_IDUNIT_H
#define TALLERZ_IDUNIT_H

#include <common/Types/UnitType.h>
class UnitID {
  static unsigned long nextid;
 private:
  UnitType type;
  unsigned long id;
 public:
  explicit UnitID(const UnitType &type);
  bool operator<(const UnitID &other) const;
  bool operator==(const UnitID &other) const;
  bool operator!=(const UnitID &other) const;
  UnitType getType() const;
  template<class Archive>
  void serialize(Archive &archive){
    archive(type,id);
  }
};

#endif //TALLERZ_IDUNIT_H
