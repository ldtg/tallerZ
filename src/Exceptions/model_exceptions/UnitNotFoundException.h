#ifndef TALLERZ_UNITNOTFOUNDEXCEPTION_H
#define TALLERZ_UNITNOTFOUNDEXCEPTION_H

#include <exception>
#include <string>
class UnitNotFoundException : public std::exception {
 private:
  const std::string msg;
 public:
  explicit UnitNotFoundException(const std::string &msg);
  virtual const char * what() const throw() override;
};

#endif //TALLERZ_UNITNOTFOUNDEXCEPTION_H
