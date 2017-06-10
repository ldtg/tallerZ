#ifndef TALLERZ_SERVERGAMERUNNER_H
#define TALLERZ_SERVERGAMERUNNER_H
#include <common/Thread/Thread.h>
#include <server/model/Events/serverEvent.h>
#include <server/model/protectedGameController.h>
class serverGameRunner : public Thread {
 private:
  protectedGameController &gameController;
  bool open;
 public:
  serverGameRunner(protectedGameController &gameController);
  virtual void run() override;
  void stop();
  bool isOpen() const;
};

#endif //TALLERZ_SERVERGAMERUNNER_H
