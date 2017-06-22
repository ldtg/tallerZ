#ifndef TALLERZ_SERVERCLIENTPROXY_H
#define TALLERZ_SERVERCLIENTPROXY_H

#include <common/Thread/Thread.h>
#include <common/Socket/Socket.h>
#include <common/IDs/PlayerID.h>
#include "GameController.h"
class serverCommandReceiver : public Thread {
 private:
  Socket &socketClient;
  GameController &gameController;
  bool open;
  PlayerID id;
 public:
  serverCommandReceiver(Socket &socket, GameController &gc, const PlayerID &id);
  virtual void run() override;
  void stop();
  bool isOpen() const;
  ~serverCommandReceiver();
};

#endif //TALLERZ_SERVERCLIENTPROXY_H
