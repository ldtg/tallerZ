#ifndef TALLERZ_DATACLIENTCONNECTEDMESSAGE_H
#define TALLERZ_DATACLIENTCONNECTEDMESSAGE_H
#include <cereal/types/string.hpp>
struct dataClientConnectedMessage {
  unsigned short team;
  std::string map;
  dataClientConnectedMessage(unsigned short team, const std::string &map);
  dataClientConnectedMessage();
  template<class Archive>
  void serialize(Archive &archive) {
    archive(team, map);
  }
};

#endif //TALLERZ_DATACLIENTCONNECTEDMESSAGE_H
