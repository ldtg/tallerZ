
#ifndef TALLERZ_BUILDINGNOTFOUNDEXCEPTION_H
#define TALLERZ_BUILDINGNOTFOUNDEXCEPTION_H

#include <string>
#include <exception>

class BuildingNotFoundException : public std::exception {
 private:
  const std::string msg;
 public:
  explicit BuildingNotFoundException(const std::string &msg);
  virtual const char * what() const throw() override;
};


#endif //TALLERZ_BUILDINGNOTFOUNDEXCEPTION_H
