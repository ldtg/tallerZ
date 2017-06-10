#ifndef TALLERZ_SERVERCLIENTPROXY_H
#define TALLERZ_SERVERCLIENTPROXY_H

#include <common/Thread/Thread.h>
#include <common/Socket/Socket.h>
#include <common/IDs/PlayerID.h>
#include "serverGameController.h"
class serverCommandReceiver : public Thread {
 private:
  Socket &socketClient;
  serverGameController &gameController;
  bool open;
 public:
  serverCommandReceiver(Socket &socket, serverGameController &gc);
  virtual void run() override;
  void stop();
  bool isOpen() const;
  ~serverCommandReceiver();
};

#endif //TALLERZ_SERVERCLIENTPROXY_H
