#ifndef TALLERZ_BULLETID_H
#define TALLERZ_BULLETID_H

class BulletID {
  static unsigned long nextid;
 private:
  unsigned long id;
 public:
  BulletID();
  bool operator<(const BulletID &other) const;
};

#endif //TALLERZ_BULLETID_H
