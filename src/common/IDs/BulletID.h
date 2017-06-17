#ifndef TALLERZ_BULLETID_H
#define TALLERZ_BULLETID_H

class BulletID {
  static unsigned long nextid;
 public:
  unsigned long id;
 public:
  BulletID();
  bool operator<(const BulletID &other) const;
  unsigned long getID() {return id;}

  template<class Archive>
  void serialize(Archive &archive) {
    archive(id);
  }
};

#endif //TALLERZ_BULLETID_H
