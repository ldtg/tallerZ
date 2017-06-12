#ifndef TALLERZ_CLIENTCOMMANDSENDER_H
#define TALLERZ_CLIENTCOMMANDSENDER_H

#include <common/Socket/Socket.h>
#include <common/Thread/Thread.h>
#include <client/model/Commands/clientCommand.h>
#include <common/Queue/Queue.h>
class clientCommandSender : public Thread{
 private:
  Socket &socket;
  Queue<clientCommand *> &queue;
  bool open;
 public:
  clientCommandSender(Socket &socket, Queue<clientCommand *> &queue);
  virtual void run() override;
  void stop();
  bool isOpen() const;
  ~clientCommandSender();
};

#endif //TALLERZ_CLIENTCOMMANDSENDER_H
