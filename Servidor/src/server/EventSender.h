#ifndef TALLERZ_SERVEREVENTSENDER_H
#define TALLERZ_SERVEREVENTSENDER_H

#include <common/Thread/Thread.h>
#include <common/Socket/Socket.h>
#include <vector>
#include <common/Queue/Queue.h>
class EventSender : public Thread{
 private:
  std::vector<Socket *> clients;
  Queue<ServerEvent*> &queue;
  bool open;
 public:
  EventSender(const std::vector<Socket *> &clients,
                    Queue<ServerEvent *> &queue);
  virtual void run() override;
  void stop();
  bool isOpen() const;
  ~EventSender();
};

#endif //TALLERZ_SERVEREVENTSENDER_H
