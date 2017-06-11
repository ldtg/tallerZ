#ifndef TALLERZ_CLIENTEVENTRECEIVER_H
#define TALLERZ_CLIENTEVENTRECEIVER_H

#include <common/Thread/Thread.h>
#include <common/Socket/Socket.h>
#include <common/Queue/Queue.h>
class clientEventReceiver : public Thread{
 private:
  Socket &srvSocket;
  Queue<Event *> &queue;
  bool open;
 public:
  clientEventReceiver(Socket &srvSocket, Queue<Event *> &queue);
  virtual void run() override;
  void stop();
  bool isOpen() const;
  ~clientEventReceiver();
};

#endif //TALLERZ_CLIENTEVENTRECEIVER_H
