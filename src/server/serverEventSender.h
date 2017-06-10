#ifndef TALLERZ_SERVEREVENTSENDER_H
#define TALLERZ_SERVEREVENTSENDER_H

#include <common/Thread/Thread.h>
#include <common/Socket/Socket.h>
#include <vector>
#include <common/Queue/Queue.h>
class serverEventSender : public Thread{
 private:
  std::vector<Socket *> clients;
  Queue<serverEvent*> &queue;
  bool open;
 public:
  serverEventSender(const std::vector<Socket *> &clients,
                    Queue<serverEvent *> &queue);
  virtual void run() override;
  void stop();
  bool isOpen() const;
  ~serverEventSender();
};

#endif //TALLERZ_SERVEREVENTSENDER_H
