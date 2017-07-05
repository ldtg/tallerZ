#ifndef TALLERZ_CLIENTEVENTRECEIVER_H
#define TALLERZ_CLIENTEVENTRECEIVER_H

#include <common/Thread/Thread.h>
#include <common/Socket/Socket.h>
#include <common/Queue/Queue.h>

class ClientEventReceiver : public Thread{
 private:
  Socket &srvSocket;
  Queue<Event *> &queue;
  bool open;

 public:
  ClientEventReceiver(Socket &srvSocket, Queue<Event *> &queue);
  virtual void run() override;
  void stop();
  bool isOpen() const;
  ~ClientEventReceiver();
};

#endif //TALLERZ_CLIENTEVENTRECEIVER_H
