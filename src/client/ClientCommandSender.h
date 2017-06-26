#ifndef TALLERZ_CLIENTCOMMANDSENDER_H
#define TALLERZ_CLIENTCOMMANDSENDER_H

#include <common/Socket/Socket.h>
#include <common/Thread/Thread.h>
#include <client/model/Commands/ClientCommand.h>
#include <common/Queue/Queue.h>

class ClientCommandSender : public Thread{
 private:
  Socket &socket;
  Queue<ClientCommand *> &queue;
  bool open;

 public:
  ClientCommandSender(Socket &socket, Queue<ClientCommand *> &queue);
  virtual void run() override;
  void stop();
  bool isOpen() const;
  ~ClientCommandSender();
};

#endif //TALLERZ_CLIENTCOMMANDSENDER_H
