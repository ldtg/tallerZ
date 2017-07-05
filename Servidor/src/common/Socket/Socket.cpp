#include "Socket.h"
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>

Socket::Socket(int fd) : socketfd(fd) {}

Socket::Socket() {
  this->socketfd = INVALID_SOCKET;
}

void Socket::connectToServer(const std::string &host, const std::string
&service) {
  bool seConecto = false;
  struct addrinfo *result = generarResultCliente(host, service);
  struct addrinfo *ptr = NULL;
  for (ptr = result; ptr != NULL && !seConecto; ptr = ptr->ai_next) {
    crearSocket(ptr);
    conectarSocket(ptr);
    seConecto = true;
  }
  freeaddrinfo(result);
  if (!seConecto) {
    throw SocketException("No se pudo conectar");
  }
}

void Socket::bindandlisten(const std::string &service) {
  struct addrinfo *result = generar_result_server(service);
  crearSocket(result);
  bindSocket(result);
  freeaddrinfo(result);
  listenSocket();
}

Socket Socket::acceptConnection() {
  int aux = accept(this->socketfd, NULL, NULL);
  if (aux == INVALID_SOCKET) {
    std::stringstream auxstr;
    auxstr << "Error en accept  " << strerror(errno) << std::endl;
    throw SocketException(auxstr.str());
  }
  return Socket(aux);
}

void Socket::shutdownConnection(ShutdownMode mode) {
  shutdown(this->socketfd, mode);
}

void Socket::send_tcp(const char *data, size_t data_len) {
  size_t bytes_eviados = 0;
  while (bytes_eviados < data_len) {
    ssize_t s = send(this->socketfd,
                     data + bytes_eviados,
                     data_len - bytes_eviados,
                     MSG_NOSIGNAL);

    if (s <= 0) {
      std::stringstream auxstr;
      auxstr << "Error send  " << strerror(errno) << std::endl;
      throw SocketException(auxstr.str(), s);
    } else {
      bytes_eviados += s;
    }
  }
}

void Socket::receive_tcp(char *data, size_t data_len) const {
  size_t bytes_recibidos = 0;
  while (bytes_recibidos < data_len) {
    ssize_t s = recv(this->socketfd,
                     data + bytes_recibidos,
                     data_len - bytes_recibidos,
                     MSG_NOSIGNAL);

    if (s <= 0) {
      std::stringstream auxstr;
      auxstr << "Error recv  " << strerror(errno) << std::endl;
      throw SocketException(auxstr.str(), s);
    } else {
      bytes_recibidos += s;
    }
  }
}

void Socket::send_str_preconcatenated(const std::string &str_snd) {
  std::string str(str_snd);
  uint32_t size = (uint32_t) str.size();
  if (size > MAX_MSG_LEN)
    throw SocketException("ERROR SEND STR");
  uint32_t sizets = htonl(size);
  send_tcp((char *) &sizets, sizeof(uint32_t));
  send_tcp(str.c_str(), size);
}

std::string Socket::rcv_str_preconcatenated() {
  char buff[MAX_MSG_LEN] = "";
  uint32_t sizercv;
  receive_tcp((char *) &sizercv, sizeof(uint32_t));
  uint32_t size = ntohl(sizercv);
  if (size > MAX_MSG_LEN)
    throw SocketException("ERROR RCV STR");
  receive_tcp(buff, size);
  std::string aux(buff, size);
  return aux;
}

struct addrinfo *Socket::generarResultCliente(std::string host,
                                              std::string service) {
  struct addrinfo hints;
  struct addrinfo *result;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = 0;

  int s = getaddrinfo(host.c_str(), service.c_str(), &hints, &result);
  if (s != 0) {
    std::stringstream aux;
    aux << "Error en getaddrinfo " << gai_strerror(s) << std::endl;
    throw SocketException(aux.str());
  }
  return result;
}

void Socket::crearSocket(addrinfo *pAddrinfo) {
  int enable = 1;

  this->socketfd = socket(pAddrinfo->ai_family, pAddrinfo->ai_socktype,
                          pAddrinfo->ai_protocol);

  if (this->socketfd == -1) {
    std::stringstream aux;
    aux << "Error al crear " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }

  if (setsockopt(this->socketfd,
                 SOL_SOCKET,
                 SO_REUSEPORT,
                 &enable,
                 sizeof(int)) < 0) {
    close(this->socketfd);
    freeaddrinfo(pAddrinfo);
    std::stringstream aux;
    aux << "Error en setsockop " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }
}

void Socket::conectarSocket(addrinfo *pAddrinfo) {
  if (connect(this->socketfd, pAddrinfo->ai_addr, pAddrinfo->ai_addrlen)
      == -1) {
    close(this->socketfd);
    std::stringstream aux;
    aux << "Error en connect " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }
}

addrinfo *Socket::generar_result_server(std::string service) {
  struct addrinfo hints;
  struct addrinfo *result;
  memset(&hints, 0, sizeof(struct addrinfo));

  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;
  int s = getaddrinfo(NULL,
                      service.c_str(),
                      &hints,
                      &result);

  if (s != 0) {
    std::stringstream aux;
    aux << "Error en getaddrinfo " << gai_strerror(s) << std::endl;
    throw SocketException(aux.str());
  }
  return result;
}

void Socket::bindSocket(addrinfo *pAddrinfo) {
  if (bind(this->socketfd, pAddrinfo->ai_addr, pAddrinfo->ai_addrlen) == -1) {
    std::stringstream aux;
    aux << "Error en bind " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }
}

void Socket::listenSocket() {
  if (listen(this->socketfd, MAX_CLIENTES_ESPERA) == -1) {
    std::stringstream aux;
    aux << "Error en listen " << strerror(errno) << std::endl;
    throw SocketException(aux.str());
  }
}

Socket::Socket(Socket &&otro) {
  this->socketfd = otro.socketfd;
  otro.socketfd = INVALID_SOCKET;
}

Socket &Socket::operator=(Socket &&otro) {
  this->socketfd = otro.socketfd;
  otro.socketfd = INVALID_SOCKET;
  return *this;
}
bool Socket::isValid() {
  return this->socketfd != INVALID_SOCKET;
}
void Socket::closeSocket() {
  if (this->isValid())
    close(this->socketfd);
  this->socketfd = INVALID_SOCKET;
}

Socket::~Socket() {
  this->closeSocket();
}






