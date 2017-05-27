#ifndef TALLERZ_BUILDID_H
#define TALLERZ_BUILDID_H

#include "BuildType.h"
class BuildID {
 private:
  static unsigned long nextid;
  BuildType type;
  unsigned long id;
 public:
  explicit BuildID(const BuildType &buildType);
  bool operator<(const BuildID &other) const;
  BuildType getType() const;
};

#endif //TALLERZ_BUILDID_H
