#include "DataClientConnectedMessage.h"
DataClientConnectedMessage::DataClientConnectedMessage(unsigned short team,
                                                       const std::string &map)
    : team(team), map(map) {}
DataClientConnectedMessage::DataClientConnectedMessage() {}
