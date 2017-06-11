#include "dataClientConnectedMessage.h"
dataClientConnectedMessage::dataClientConnectedMessage(unsigned short team,
                                                       const std::string &map)
    : team(team), map(map) {}
dataClientConnectedMessage::dataClientConnectedMessage() {}
