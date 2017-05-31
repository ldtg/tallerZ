#ifndef TALLERZ_PLAYERID_H
#define TALLERZ_PLAYERID_H
#include <string>
class PlayerID {
  static unsigned short nextid;
 private:
  //Agregarle un color??
  unsigned short id;
  std::string name;//cambiar por color
 public:
  PlayerID(const std::string &name);
  std::string getName() const;
  bool operator<(const PlayerID &other) const;
  bool operator==(const PlayerID &other) const;
  bool operator!=(const PlayerID &other) const;
};

#endif //TALLERZ_PLAYERID_H
