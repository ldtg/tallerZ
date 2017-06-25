#ifndef TALLERZ_DATACLIENTCONNECTEDMESSAGE_H
#define TALLERZ_DATACLIENTCONNECTEDMESSAGE_H
#include <cereal/types/string.hpp>
struct  DataClientConnectedMessage {
  unsigned short team;
  std::string map;
  DataClientConnectedMessage(unsigned short team, const std::string &map);
  DataClientConnectedMessage();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(team, map);
  }
};

#endif //TALLERZ_DATACLIENTCONNECTEDMESSAGE_H
