#ifndef TALLERZ_PLAYERID_H
#define TALLERZ_PLAYERID_H
#include <string>
#include "PlayerColor.h"

class PlayerID {
  static unsigned short nextid;
 private:
  unsigned short id;
  PlayerColor color;
 public:
  explicit PlayerID(const PlayerColor &color);
  std::string getColor() const;
  bool operator<(const PlayerID &other) const;
  bool operator==(const PlayerID &other) const;
  bool operator!=(const PlayerID &other) const;
};

#endif //TALLERZ_PLAYERID_H
