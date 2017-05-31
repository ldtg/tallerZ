#ifndef TALLERZ_UNABLETOFINDAPATHEXCEPTION_H
#define TALLERZ_UNABLETOFINDAPATHEXCEPTION_H
#include <exception>
#include <string>
class UnableToFindAPathException : public std::exception {
 private:
  const std::string msg;
 public:
  explicit UnableToFindAPathException(const std::string &msg);
  virtual const char * what() const throw() override;
};

#endif //TALLERZ_UNABLETOFINDAPATHEXCEPTION_H
