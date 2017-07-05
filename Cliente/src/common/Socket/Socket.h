#ifndef TALLERZ_SOCKET_H
#define TALLERZ_SOCKET_H
#include <string>
#include "SocketException.h"
#define MAX_MSG_LEN 265535
#define MAX_CLIENTES_ESPERA 10
#define INVALID_SOCKET -1
enum ShutdownMode { READ, WRITE, READWRITE };
class Socket {
 private:
  int socketfd;
  struct addrinfo *generarResultCliente(std::string basic_string,
                                        std::string basicString);
  void crearSocket(addrinfo *pAddrinfo);
  void conectarSocket(addrinfo *pAddrinfo);
  addrinfo *generar_result_server(std::string basic_string);
  void bindSocket(addrinfo *pAddrinfo);
  void listenSocket();
  explicit Socket(int fd);

 public:
  Socket();
  // Conecta con el host y el servicio dado
  void connectToServer(const std::string &host, const std::string &service);
  // Bindea en port y pone el estado del socket en listen
  void bindandlisten(const std::string &service);
  // Acepta una coneccion entrante y retorna el socket
  // correspondiente a esa coneccion. Si no hay conecciones
  // entrantes espera hasta que haya alguna.
  Socket acceptConnection();
  // Cierra la coneccion del socket del modo indicado por mode
  void shutdownConnection(ShutdownMode mode);
  // Envia a traves del socket data_len bytes a partir de la posicion apuntada
  // por data
  void send_tcp(const char *data, size_t data_len);
  // Recibe a traves del socket data_len bytes en la posicion apuntada
  // por data
  void receive_tcp(char *data, size_t data_len) const;
  //Retorna true si el socket esta en un estado valido
  bool isValid();
  // Envia a traves del sockey un string, enviando primero el tamaño como
  // 4 bytes preconcatenados
  void send_str_preconcatenated(const std::string &str_snd);
  // Recibe a traves del sockey un string, obteniendo primero el tamaño como
  // 4 bytes preconcatenados
  std::string rcv_str_preconcatenated();
  // Cierra el socket
  void closeSocket();
  ~Socket();
  Socket(const Socket &otro) = delete;
  Socket &operator=(const Socket &otro) = delete;
  Socket(Socket &&otro);
  Socket &operator=(Socket &&otro);
};
#endif //TALLERZ_SOCKET_H