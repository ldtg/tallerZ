#ifndef TALLERZ_PLAYERID_H
#define TALLERZ_PLAYERID_H
#include <string>
#include <common/Types/PlayerColor.h>

class PlayerID {
  static unsigned short nextid;
 private:
  unsigned short id;
  PlayerColor color;
 public:
  explicit PlayerID(const PlayerColor &color);
  bool isGaia() const;
  unsigned short getID() const;
  std::string getColor() const;
  bool operator<(const PlayerID &other) const;
  bool operator==(const PlayerID &other) const;
  bool operator!=(const PlayerID &other) const;
  template<class Archive>
  void serialize(Archive &archive){
    archive(color,id);
  }
};

#endif //TALLERZ_PLAYERID_H
