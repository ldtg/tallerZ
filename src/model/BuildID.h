#ifndef TALLERZ_BUILDID_H
#define TALLERZ_BUILDID_H

#include "BuildType.h"
class BuildID {
 private:
  static unsigned long nextid;
  const BuildType type;
  const unsigned long id;
 public:
  explicit BuildID(const BuildType& buildType);
  bool operator<(const BuildID &other) const;
};

#endif //TALLERZ_BUILDID_H
