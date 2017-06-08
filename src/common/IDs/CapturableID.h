#ifndef TALLERZ_CAPTURABLEID_H
#define TALLERZ_CAPTURABLEID_H

#include <common/Types/CapturableType.h>
class CapturableID {
  static unsigned short nextid;
 private:
  unsigned short id;
  CapturableType type;
 public:
  explicit CapturableID(const CapturableType &type);
  CapturableID() {};
  CapturableType getType() const;
  bool operator<(const CapturableID &other) const;
  bool operator==(const CapturableID &other) const;
  bool operator!=(const CapturableID &other) const;
  template<class Archive>
  void serialize(Archive &archive) {
    archive(type, id);
  }
};

#endif //TALLERZ_CAPTURABLEID_H
