#ifndef TALLERZ_PLAYERID_H
#define TALLERZ_PLAYERID_H
#include <string>
class PlayerID {
  static unsigned long nextid;
 private:
  unsigned short id;
  std::string name;
 public:
  PlayerID(const std::string &name);
  std::string getName() const;
  bool operator<(const PlayerID &other) const;
};

#endif //TALLERZ_PLAYERID_H
