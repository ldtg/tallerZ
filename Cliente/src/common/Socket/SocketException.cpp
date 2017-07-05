#include <string>
#include "SocketException.h"
SocketException::SocketException(const std::string msg) : msg(msg),
                                                          bytesTransferidos
                                                              (0) {}
const char *SocketException::what() const throw() {
  return msg.c_str();
}
SocketException::SocketException(const std::string msg,
                                 ssize_t bytesTrasferidos) :
    msg(msg), bytesTransferidos(bytesTrasferidos) {}
ssize_t SocketException::getBytesTransferidos() const {
  return this->bytesTransferidos;
}
