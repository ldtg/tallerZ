#ifndef TALLERZ_CLIENTE_LOCK_H
#define TALLERZ_CLIENTE_LOCK_H

#include <mutex>

class Lock {
 private:
  std::mutex &m;

 public:
  explicit Lock(std::mutex &m) : m(m) {
    m.lock();
  }

  ~Lock() {
    m.unlock();
  }

 private:
  Lock(const Lock&) = delete;
  Lock& operator=(const Lock&) = delete;
  Lock(Lock&&) = delete;
  Lock& operator=(Lock&&) = delete;
};

#endif //TALLERZ_CLIENTE_LOCK_H
