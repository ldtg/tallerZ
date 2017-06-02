#ifndef TALLERZ_CAPTURABLEID_H
#define TALLERZ_CAPTURABLEID_H

#include "CapturableType.h"
class CapturableID {
  static unsigned short nextid;
 private:
  unsigned short id;
  CapturableType type;
 public:
  explicit CapturableID(const CapturableType &type);
  bool operator<(const CapturableID &other) const;
  bool operator==(const CapturableID &other) const;
  bool operator!=(const CapturableID &other) const;
};

#endif //TALLERZ_CAPTURABLEID_H
