#ifndef TALLERZ_BUILDID_H
#define TALLERZ_BUILDID_H

#include <common/Types/BuildType.h>

class BuildID {
 private:
  static unsigned long nextid;
  BuildType type;
  unsigned long id;

 public:
  explicit BuildID(const BuildType &buildType);
  BuildID(){};
  bool operator<(const BuildID &other) const;
  BuildType getType() const;
  template<class Archive>
  void serialize(Archive &archive){
    archive(type,id);
  }
};

#endif //TALLERZ_BUILDID_H
