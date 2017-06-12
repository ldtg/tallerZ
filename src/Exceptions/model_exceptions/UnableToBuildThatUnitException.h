#ifndef TALLERZ_UNABLETOBUILDTHATUNITEXCEPTION_H
#define TALLERZ_UNABLETOBUILDTHATUNITEXCEPTION_H
#include <exception>
#include <string>
class UnableToBuildThatUnitException: public std::exception {
 private:
  const std::string msg;
 public:
  explicit UnableToBuildThatUnitException(const std::string &msg);
  virtual const char *what() const throw() override;
};
#endif //TALLERZ_UNABLETOBUILDTHATUNITEXCEPTION_H
